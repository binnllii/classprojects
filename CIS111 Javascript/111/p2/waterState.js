function waterstate(temperature){
	if(temperature < 32)
		return "Solid";
	
	if(temperature > 32 && temperature < 212)
		return "Liquid";
	
	if (temperature > 212 && temperature < 21141)
		return "Gas";
	
	if (temperature >= 21141)
		return "Plasma";
};

var main = function(){
	var temperature = parseFloat(prompt("enter in temperature"));
	result = waterstate(temperature);
	console.log("Temperature:  " + temperature + " degrees F.\n"
		+ "Water State: " + result + ". ");
	alert("Temperature " + temperature + " degrees F.\n"
		+ "Water State: " + result + ".");
};

main();




