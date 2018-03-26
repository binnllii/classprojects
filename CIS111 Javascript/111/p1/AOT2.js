var a= Number(prompt("Please enter your first number"));
var b= Number(prompt("Please enter your second number"));
var c= Number(prompt("Please enter your third number"));
var p=(a+b+c)/2;
var area=Math.sqrt(p*((p-a)*(p-b)*(p-c)))
console.log(area);
alert(area);