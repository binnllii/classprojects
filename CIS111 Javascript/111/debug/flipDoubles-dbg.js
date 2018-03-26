//enter strict mode
"use strict";

//flipCoin
//returns 1 for heads, or 0 for tails
var flipCoin = function() {
    var face = Math.floor(Math.random() * 2);
    if (face == 1)
        return "Heads";
    else
        return "Tails";
};

//1. define the onclick handler
var main = function() {
    var result = "",
        count = 1;

    //a. get user input
    var target = document.getElementById("inBox").value;

    //b. flip coins until doubles
    var coinFace1 = flipCoin();
    var coinFace2 = flipCoin();
    //doubles?
    while (((coinFace1 != target) || (coinFace2 != target))) {
        //flip coins
        coinFace1 = flipCoin();
        coinFace2 = flipCoin();
        ++count;
    }

    //c. display resuls on web page, and update images
    document.getElementById("outDiv").innerHTML = "Double " +
        target + "! in " + count + " flips";
    document.getElementById("img1").src = "images/" + target + ".jpg";
    document.getElementById("img2").src = "images/" + target + ".jpg";

};

//2. grab the button
var bttn1 = document.getElementById("bttn1");

//3.register the handler
bttn1.onclick = main;
