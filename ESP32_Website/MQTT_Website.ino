#include <WiFi.h>
#include <PubSubClient.h>
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"


//--------------------------------------------------------
// Connection setup
const char* ssid = "Tracen";
const char* password = "qwertyui";
const char* mqtt_server = "broker.hivemq.com";
//--------------------------------------------------------

//--------------------------------------------------------
// MQTT Setup
WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE  (50)
char msg[MSG_BUFFER_SIZE];
int value = 0;
char audioMessageReceive[50];

DFRobotDFPlayerMini mp3;
void printDetail(uint8_t type, int value);
//--------------------------------------------------------

//--------------------------------------------------------
//Variable to Control Audio
String audioTitle;
//--------------------------------------------------------

//--------------------------------------------------------
// WiFi Setup
void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
//--------------------------------------------------------

//--------------------------------------------------------
// Callback to subscribe MQTT message
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    audioMessageReceive[i] = (char)payload[i];
  }
  Serial.println();
  if(client.subscribe("audio")){
    audioTitle = String(audioMessageReceive);
    if(audioTitle == "Audio 1"){
      mp3.volume(30);
      mp3.play(1);  
      delay(5000);
    } else if(audioTitle == "Audio 2"){
      mp3.volume(30);
      mp3.play(2);  
      delay(5000);
    } else if(audioTitle == "Audio 3"){
      mp3.volume(30);
      mp3.play(3);  
      delay(5000);
    } else if(audioTitle == "Audio 4"){
      mp3.volume(30);
      mp3.play(4);  
      delay(5000);
    } else if(audioTitle == "Audio 5"){
      mp3.volume(30);
      mp3.play(5);  
      delay(5000);
    }
  }
}
//--------------------------------------------------------


//--------------------------------------------------------
// Reconnect to WiFi
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      client.subscribe("audio");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
//--------------------------------------------------------


void setup() {
  Serial2.begin(9600);
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!mp3.begin(Serial2)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));

  mp3.EQ(DFPLAYER_EQ_NORMAL);
  mp3.outputDevice(DFPLAYER_DEVICE_SD);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
