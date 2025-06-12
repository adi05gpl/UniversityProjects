const WHITE_KEYS = ['z', 'x', 'c', 'v', 'b', 'n', 'm']          // clapele albe
const BLACK_KEYS = ['s', 'd', 'g', 'h', 'j']                  // clapele negre

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

function msj_dinamic_1(){                                 // functia pentru a arata mesajele random, in text box, cu ajutorul butonului start
  var rezult = '';
  var tasta = "ZSXDCVGBHNJM";
  var lungTasta = tasta.length;
  var i, rnum;
  for ( i = 0; i < lungTasta; i++ ) {
      rnum = Math.floor(Math.random() * lungTasta);
      rezult += tasta.substring(rnum,rnum+1);
      Timp1=setTimeout("msj_dinamic_1()",10000);
}
    document.loc_mes_2.mesaj.value = rezult;
}

function stop_1(){                              // functia de a oprii iteratia mesajelor, cu ajutorul butonului stop

clearTimeout(Timp1);
}

