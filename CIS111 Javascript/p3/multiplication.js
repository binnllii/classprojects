//"classic" function-- accepts an argument, returns a value
function multiply(num){
	var s = "";
	for(var i = 1; i <= 10; i++)
		s = s + i + " * " + num + " = " + i * num + "</br>";
		//s = num + " * " + s + i + " = " + i * num + "</br>";
		return s;

}

 
//define the onclick handler
var main = function(){
	//get value entered by user in web page
	var s = document.getElementById('inputBox').value;
	
	//display result on web page
	document.getElementById('outputDiv').innerHTML = multiply(s);
};

//select the button
var button1 = document.getElementById("btn1");

//register the handler
//main is a "call-back" function
button1.onclick = main; 
