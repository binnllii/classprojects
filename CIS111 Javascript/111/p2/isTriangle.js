function isTriangle(a, b, c){
	if((a + b) <= c){
		return(false);
	}
	if((a + c) <= b){
		return(false);
	}
	if((b + c) <= a){
		return(false);
	}
	else{
		return(true);
	}
};

function main(){
	var a = parseFloat(prompt("Please enter the first side"));
	var b = parseFloat(prompt("Please enter the second side"));
	var c = parseFloat(prompt("Please enter the third side"));
	
result = isTriangle(a,b,c);

alert("Sides: " + a + "," + b + "," + c + "\n" + "Triangle Possible?" + result);
console.log("Sides: " + a + "," + b + "," + c + "\n" + "Triangle Possible?" + result);

};
main();