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

function areaOfTriangle(a, b, c){
	var p=(a+b+c)/2;
	return Math.sqrt(p*((p-a)*(p-b)*(p-c)))
}

function main(){
	var a = parseFloat(prompt("Please enter the first side"));
	var b = parseFloat(prompt("Please enter the second side"));
	var c = parseFloat(prompt("Please enter the third side"));

	if(isTriangle(a,b,c)==false){
		alert("Error-- triangle not possible for sides entered")
	}
	else{
		area = areaOfTriangle(a, b, c)
		console.log("area = " + area);
		alert("area =" + area);
	}
}

main();