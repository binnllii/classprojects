//define a Dice object, properties and methods
var Dice = {
    sides: 6,

    rollDie: function() {
        return Math.floor(Math.random() * this.sides) + 1;
    },
 /* roll two dice and return the number rolled.         
  * When a function is called as a method,          
  * it's this keyword is set to the object          
  * containing the method.          
  */
    rollDice: function() {

        var num = this.rollDie() + this.rollDie();
        return num;
    },
//roll two dice until you hit double n's         
//return the number of rolls
    rollDoubles: function(n) {
        var d1, d2, k=0;
        do {
            die1 = Dice.rollDie();
            die2 = Dice.rollDie();
            ++k;
            console.log (die1 + " " + die2);
        } while (die1 != n || die2 != n);
        return k;
    },

    URL_prefix: "http://dave-reed.com/book3e/Images/",

    getURL: function(n) {

        return this.URL_prefix + "die" + n + ".gif";
    },
    
 //roll two dice until you hit n     
 //return the number of rolls
roll_number : function (n) {

    var die1, die2;
    var count = 0;
    do {
        die1 = Dice.rollDie();
        die2 = Dice.rollDie();
        ++count;
    } while ((die1 + die2 !=n));
    $("#img1").attr("src",Dice.getURL(die1))
    $("#img2").attr("src",Dice.getURL(die2))

    return count;
    }
};
function roll_number(){

var num = parseInt(document.getElementById("inputBox").value);
    document.getElementById("outputDiv").innerHTML = "You hit your number in " + Dice.roll_number(num) + " rolls"

}
var btn1=document.getElementById("btn1")
document.getElementById("btn1").onclick= roll_number;