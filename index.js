const express = require('express');
const app = express();

const mqtt = require('mqtt');
const client  = mqtt.connect('mqtt://broker.hivemq.com');

const {send} = require('./utils/controlElement');
const port = process.env.PORT || 3000

app.set('view engine','ejs');
app.use(express.static('public'));
app.use(express.urlencoded({ extended:true }));

app.get('/',(req,res)=>{
    console.log(req.ip);
    res.render('home');
});

app.post('/send',(req,res)=>{
    var data = String(req.body.audio_kirim);
    client.publish('audio',data);
    res.redirect('/');
});

app.listen(port);