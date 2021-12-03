'use strict'
// Buat server
const express = require('express');
const app = express();
const port = process.env.PORT || 3000;

// Untuk MQTT
const mqtt = require('mqtt');
const client  = mqtt.connect('mqtt://broker.hivemq.com');
var dataC = " ";

// Terima data photo
const multer = require('multer');
const storage = multer.diskStorage({
    destination: function (req, file, cb) {
      cb(null, './public/img/data')
    },
    filename: function (req, file, cb) {
        fileExtension = file.originalname.split('.')[1];
      cb(null, Date.now()+'--'+file.fieldname+'.'+fileExtension);
    }
});
const upload = multer({storage:storage})

//Function
const {loadData,addData,detailData,send} = require('./utils/controlElement');

// Untuk view engine
app.set('view engine','ejs');
app.use(express.static('public'));
app.use(express.urlencoded({ extended:true }));

// Home
app.get('/',(req,res)=>{
    res.render('home');
});

// Send MQTT
app.post('/send',(req,res)=>{
    var data = String(req.body.audio_kirim);
    client.publish('audio',data);
    res.redirect('/');
});

// Accept photo
app.post('/photo', upload.single('image/jpeg'), (req,res)=>{
    const dataImg = Object.assign(req.file);
    addData(dataImg);
    console.log(dataImg);
    res.redirect('/');
});

app.listen(port);