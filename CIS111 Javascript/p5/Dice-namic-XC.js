var Dice = {
    sides: 6,

    rollDie: function(diceElement) {
        var rolled = Math.floor(Math.random() * this.sides) + 1;
        var diceImage = this.getURL(rolled);
        diceElement.attr("src", diceImage);
    },

    rollDice: function() {
        var dice1 = Math.floor(Math.random() * this.sides) + 1;
        var dice2 = Math.floor(Math.random() * this.sides) + 1;
        return dice1 + dice2;
    },

    rollDoubles: function(n) {
        var d1, d2, k = 0;
        do {
            d1 = this.rollDie('#img1');
            d2 = this.rollDie('#img2');
            k++
        } while (!(d1 == n && d2 == n));
        return k;

    },

    URL_prefix: "http://dave-reed.com/book3e/Images/",

    getURL: function(n) {
        return this.URL_prefix + "die" + n + ".gif"

    },


 
    roll_number: function(n) {
        var d1, d2, k = 0;
        do {
            d1 = Math.floor(Math.random() * 6) + 1;
            d2 = Math.floor(Math.random() * 6) + 1;
            k++;
        } while (!((d1 + d2) == n));
        $("#img1").attr("src", Dice.getURL(d1))
        $("#img2").attr("src", Dice.getURL(d2))
        return k;
    }
};

function roll_number() {
    var num = parseInt(document.getElementById("inputBox").value);
    var rollNum = (Dice.roll_number(num) == 1) ? "roll" : "rolls";
    document.getElementById("outputDiv").innerHTML = "You hit your number in " + Dice.roll_number(num) + " " + rollNum + "!";
}
var btn1 = document.getElementById("btn1")
document.getElementById("btn1").onclick = roll_number;