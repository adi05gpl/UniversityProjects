const WHITE_KEYS = ['1', '3', '5', '7', '9', '-', '=']          // clapele albe
const BLACK_KEYS = ['2', '4', '6', '8', '0']                  // clapele negre

const keys = document.querySelectorAll('.key')              // legatura intre clasa .key din style.css
const whiteKeys = document.querySelectorAll('.key.white')   
const blackKeys = document.querySelectorAll('.key.black')
var Timp1;

keys.forEach(key => {
  key.addEventListener('click', () => playNote(key))        // adaugarea sunetului fiecarei clape, la apasarea mouse-ului
})

document.addEventListener('keydown', e => {           //  legatura intre tastele de la tastatura, cu clapele pianului, respective
  if (e.repeat) return        // PENTRU A PUTEA OPRII SUNETUL CLAPEI, adica in cazul in care tinem apasat o tasta, sa se opreasca imediat ce sunetul a luat sfarsit
  const key = e.key
  const whiteKeyIndex = WHITE_KEYS.indexOf(key)       // clapele albe
  const blackKeyIndex = BLACK_KEYS.indexOf(key)       // clapele negre

  if (whiteKeyIndex > -1) playNote(whiteKeys[whiteKeyIndex])    // daca se apasa pe tasta "z", va suna una din clapele albe etc.
  if (blackKeyIndex > -1) playNote(blackKeys[blackKeyIndex])    // daca se apasa pe tasta "s", va suna una din clapele negre etc.
})


function playNote(key) {                                              
  const noteAudio = document.getElementById(key.dataset.note)     
  noteAudio.currentTime = 0
  noteAudio.play()
  key.classList.add('active')                                 // la apasare, clapa respectiva isi schimba culoarea in gri pentru ca a fost apasata
  noteAudio.addEventListener('ended', () => {               // aici oprim culoarea gri, adica clapa respectiva nu isi va schimba culoarea in gri pentru totdeauna,
    key.classList.remove('active')                        // in cazul in care a fost apasata, si isi va revenii la culoarea ei originala.
  })
}

if (window.XMLHttpRequest){
  xhttp=new XMLHttpRequest()
  }
else{
  xhttp=new ActiveXObject("Microsoft.XMLHTTP")
  }

function msj_dinamic_1(){                                 // functia pentru a arata mesajele random, in text box, cu ajutorul butonului start
  var rezult = [''];
  var tasta = ['1','2','3','4','5','6','7','8','9','0','-','='];
  var lungTasta = tasta.length;
  var i, rnum, j;
 
   xhttp.open("GET","http://davos.science.upm.ro/~traian/web_curs/ap_electric.php",false);
   xhttp.send("");
   xmlDoc= xhttp.responseXML;
   rnum = xmlDoc.getElementsByTagName("val")[0].childNodes[0].nodeValue;
  document.loc_mes_2.mesaj.value = '';
  for ( i = 0; i <= 5; i++ ) {
    //rnum = Math.floor(Math.random() * 100); 
    rezult.push(rnum);
    Timp1=setTimeout("msj_dinamic_1()",10000);
    document.loc_mes_2.mesaj.value += rezult[i];
  }
  document.getElementById("val").innerHTML = rnum;
}

function stop_1(){                              // functia de a oprii iteratia mesajelor, cu ajutorul butonului stop
clearTimeout(Timp1);
}