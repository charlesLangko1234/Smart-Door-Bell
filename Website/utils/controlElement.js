const fs = require('fs');

//Make directory
const dirPath = './data';
if(!fs.existsSync(dirPath)){
    fs.mkdirSync(dirPath);
}

// Make data json
const dataPath = './data/dataPhoto.json';
if(!fs.existsSync(dataPath)){
    fs.writeFileSync(dataPath,'[]','utf-8');
}

//Load Data
const loadData= ()=>{
    const file = fs.readFileSync('data/dataPhoto.json','utf-8');
    const contacts = JSON.parse(file);
    return contacts;
}

//Save data 
const saveData = (contacts)=>{
    fs.writeFileSync('data/dataPhoto.json', JSON.stringify(contacts));
}

//tambah data
const addData = (contact)=>{
    const contacts = loadData();
    contacts.push(contact);
    saveData(contacts);
}

// Ambil detail data
const detailData = (nama)=>{
    const datas = loadData();
    var dataDicari = '';
    datas.forEach(data => {
        if(data.nama_contact==nama){
            dataDicari = data;
        }
    });
    return dataDicari;
}

function send(){
    const sendBtn = document.getElementsByClassName('send')[0];
    sendBtn.addEventListener('click',()=>{
        alert('ok');
    });
}


module.exports = {loadData,addData,detailData,send}