
var table = [];
var body = document.getElementsByTagName("body")[0];
var grid = document.getElementById("grid");

body.onload = function() {
    
}

function createTable() {

    for(var i = 0; i < 10; i++) {

        table[i] = [];
        for(var j = 0; j < 10; j++) {

            table[i][j] = 0;
        }
    }
}

function clearGrid() {

    console.log("gdfg");
    for(var i = 0; i < 10; i++) {

        for(var j = 0; j < 10; j++) {

            table[i][j] = 0;
        }
    }
    updateGrid();
}

function deleteGrid() {
 
    var rows = document.getElementsByClassName("grid-row");

    for(var i = 9; i >= 0; i--) {
        grid.removeChild(rows[i]);
    }
}

function createGrid() {

    createTable();
    var block = document.createElement("div");
    block.setAttribute("class", "grid-block");
    var row = document.createElement("div");
    row.setAttribute("class", "grid-row");

    for(var i = 0; i < 10; i++) {

        var row_clone = row.cloneNode(true);
        for(var j = 0; j < 10; j++) {

            var clone = block.cloneNode(true);
            var value = "";

            if(j == 9) {
                value = "1px 1px 0 1px";
                if(i == 9)
                    value = "1px 1px 1px 1px";
            }else if(i == 9) {
                value = "1px 0 1px 1px";
            }
            clone.style.borderWidth = value;
            row_clone.appendChild(clone);
        }
        grid.appendChild(row_clone);
    }
}

function colorTable(offset) {

    for(var i = 0; i < 10; i++) {

        for(var j = 0; j < 10; j++) {

            if(offset == 0 || offset == 9) {

                var x = Math.abs(i), y = Math.abs(j - offset);
                table[x][y] = 0;
                if(x == Math.abs(y - offset)) {
    
                    table[x][y] = 1;
                }
            }else if(offset == 1 || offset == 2) {
                
                table[i][j] = 0;
                if((i * 10 + j) % 2 == (2 - offset))
                    table[i][j] = 1;
            }else if(offset == 8) {

                table[i][j] = Math.floor(Math.random() * 2);
            }
        }
    }
    updateGrid();
}

function updateGrid() {

    var blocks = document.getElementsByClassName("grid-block");

    for(var i = 0; i < 10; i++) {

        for(var j = 0; j < 10; j++) {

            var value = "no-color";
            if(table[i][j] == 1)
                value = "color";
            
            blocks[i * 10 + j].setAttribute("class", "grid-block " + value);
        }
    }
}

//////////////////////////
var number = "0";
var x = 0, y = 0, res = 0;
var view = document.getElementById("viewNumber");
var isc = false;
var sym = "";

function addDigit(digit) {

    if(number == "0" || isc == true) {

        number = "";
        isc = false;
    }
    number += digit;
    view.value = number;
}

function clearNumber() {

    number = "0";
    view.value = number;
}

function deleteDigit() {

    number = number.slice(0, -1);
    if(number == "")
        number = "0"
    view.value = number;
}

function sum() {

    var val = parseFloat(view.value);
    isc = true;
    res += val;
    view.value = res;
    sym = "+";
}

function substract() {

    var val = parseFloat(view.value);
    isc = true;
    res -= val;
    view.value = res;
    sym = "-";
}

function multiply() {

    var val = parseFloat(view.value);
    isc = true;
    res = res == 0 ? val : res * val;
    view.value = res;
    sym = "x";
}

function divide() {

    var val = parseFloat(view.value);
    isc = true;
    res = res == 0 ? val : res / val;
    view.value = res;
    sym = "/";
}

function equals() {

    var val = parseFloat(view.value);
    isc = false;
    if(sym == "+") {

        res += val;
    }else if(sym == "-") {

        res -= val;
    }else if(sym == "x") {

        res *= val;
    }else if(sym == "/") {

        res /= val;
    }
    sym = "";
    view.value = res;
}