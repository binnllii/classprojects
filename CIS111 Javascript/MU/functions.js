function arrAvg(numbers) {
	tot = 0;
	for(var i = 0; i < numbers.length; i++) {
		tot = tot + numbers[i];
	}
	var avg = tot / numbers.length;
	return avg;
}


	
function oneCharPerLine(userString) {
	str = "\n" ;	

	for(var i = 0; i < userString.length; i++) {
		str = str + userString[i] + '\n';
		
	}
	return str;
}


var translation = {
	"A" : "alpha",
	"B" : "bravo",
	"C" : "charlie",
	"D" : "delta",
	"E" : "echo",
	"F" : "foxtrot",
	"G" : "golf",
	"H" : "hotel",
	"I" : "india",
	"J" : "juliett",
	"K" : "kilo",
	"L" : "lima",
	"M" : "mike",
	"N" : "november",
	"O" : "oscar",
	"P" : "papa",
	"Q" : "quebec",
	"R" : "romeo",
	"S" : "sierra",
	"T" : "tango",
	"U" : "uniform",
	"V" : "victor",
	"W" : "whiskey",
	"X" : "x-ray",
	"Y" : "yankee",
	"z" : "zulu",
	"1" : "one",
	"2" : "two",
	"3" : "three",
	"4" : "four",
	"5" : "five",
	"6" : "six",
	"7" : "seven",
	"8" : "eight",
	"9" : "nine",
	"0" : "zero"
};




function ltrToNATO(character) {
	if(translation[character.toUpperCase()] == undefined)
		return character
	return translation[character.toUpperCase()];
};





function wordToNATO1(word) {
	var string = "";
	for(var i = 0; i < word.length; i++){
		string = string + ltrToNATO(word[i]) + " ";
	}
	return string;

};

	
function wordToNATO2(phrase) {
	var arr = phrase.split(" ")
	var str = "";
	for (var i = 0; i < arr.length; i++) {
		
			str = str + wordToNATO1(arr[i]) + " ";

	}
	return str;
};






function roll_number(){

var num = document.getElementById("inputBox").value;
    document.getElementById("outputDiv").innerHTML = wordToNATO2(num) 

}
var btn1=document.getElementById("btn1")
document.getElementById("btn1").onclick= roll_number;

