
// area of a triangle
function areaOfTriangle(a, b, c){
	var p=(a+b+c)/2;
	return Math.sqrt(p*((p-a)*(p-b)*(p-c)))
}


function main(){
	var side1 = parseFloat(prompt("Please enter your first number of the triangle"));
	var side2 = parseFloat(prompt("Please enter your second number of the triangle"));
	var side3 = parseFloat(prompt("Please enter your third number of the triangle"));
	var area = areaOfTriangle(side1,side2,side3);
	area = area.toFixed(2)
	console.log(area)
	alert(area);
}
//call main
main();