# SMART DOOR BELL

Kesulitan karena tidak bisa memantau tamu yang datang ke rumah karena tidak sedang berada di rumah merupakan masalah yang berusaha project kami selesaikan. Berdasar dari masalah inilah kami berusaha membuat **Smart Door Bell** yang mana akan membantu pemilik rumah dalam pemantauan tamu saat dia tidak berada di rumah. Alat ini dilengkapi juga dengan sistem pemutar audio, sehingga pemilik rumah bisa menympaikan pesannya kepada tamu ketika tidak sedang berada di rumah.

<ul>
  <li><a href="#Packaging">Packaging</a>
  <li><a href="#software_module">Software Module</a>
</ul>

## Packaging
<div id="Packaging"></div>
<img src="https://github.com/charlesLangko1234/Smart-Door-Bell/blob/main/Documentation/Bentuk%20Fisik%20ALat.jpg" align="left" alt="Bentuk Luar Alat" style="width: 200px; height:400px;"/>
  Berikut adalah gambaran fisik bentuk alat. Packaging alat ini dibuat dengan menempatkan komponen kedalam project box X5 berukuran 14.5 x 9.5 x 5 cm. Project box juga diberi lubang untuk speaker, kamera, infrared sensor, serta lubang untuk menghubungkan Smart Door Bell dengan sumber tegangan. Bahan project box ini juga membuat alat ini lebih ringan.<br>
  <br>
  Dibagian dalam alat sendiri sudah terdapat bebrapa komponen, yaitu DFPlayer mini, speaker 8 ohm, LED, IR Sensor, ESP32 Cam, ESP32, serta micro usb dip socket. Bagian dalam alat sendiri masih menggunakan jumper untuk menghubungkan setiap komponen. PCB tidak digunakan karena ukurannya yang besar dan akan mengubah tata letak kompoonen. Namun, untuk mengurangi ketidakteraturan tersebut, digunakan kabeltis untuk mengatur kabel didalam alat.
  
<br><br><br><br><br><br>
## Software Module
<div id="software_module"></div>

### Cara Kerja Alat
<img src="https://github.com/charlesLangko1234/Smart-Door-Bell/blob/main/Documentation/Website.jpg"/>
Cara kerja alat ini cukup mudah, yaitu ketika alat dihubugnkan dengan sumber tegangan, maka seluruh komponen yang bekerja akan menyala. Setelah akan ada jeda waktu selama beberapa detik agar Smart Door Bell berkonfigurasi dengan WiFi. Setelah terkonfigurasi, maka ESP32 cam akan membuat server yang menampilkan gambar secara terus menerus. Lalu link server yang menampilkan gambar tersebut diambil dan dimasukan kedalam website yang sudah dibuat khusus untuk alat ini. Setelah itu, gambar tamu bisa muncul secara real time.<br>
Proses pengiriman pesan sendiri dilakukan dengan menggunakan MQTT, dimana data audio pertama dipilih terlebih dahulu dari list data yang sudah ditampilkan di website Smart Door Bell System. Setelah di click dan dipastikan, data tersebut tinggal dikirim ke ESP32 via MQTT. Data tersebut lalu akan diproses dan menghasilkan ID tertentu yang sesuai dengan audio. Setelah itu, ID tersebut ke DFPlayer dan audio tersebut akan di play.
Alat ini juga dilengkapi dengan Blitz yang akan menyala ketika tamu mendekatkan wajah ke alat Smart Door Bell. IR sensor akan mendeteksi adanya halangan didepannya, lalu blitz kamera akan dinyalakan. 



