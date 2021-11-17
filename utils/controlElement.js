function send(){
    const sendBtn = document.getElementsByClassName('send')[0];
    sendBtn.addEventListener('click',()=>{
        alert('ok');
    });
}

module.exports = {send}