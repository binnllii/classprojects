function init() {
	var perimeterListener =
		document.getElementById("perimeterButton")
	perimeterListener.addEventListener("click", getPerimeter);

		var areaListener =
		document.getElementById("areaButton")
	areaListener.addEventListener("click", getArea);



	var rectangle = {
		//length: 10,
		//width: 15,
		sides: [0,0]
		area: function(){
			return this.sides(0) * this.sides[1];
		}
		perimeter: function() {
			return (this.sides[0] + this.sides[1]) * 2;
		}
		};


function getPerimeter() {
	var side1 = 
		document.getElementById("side1").value;
		side1 = parseInt(side1);
		//rectangle.length = side1;
		rectangle.sides[0] = side1;

		var side2 = 
			document.getElementById("side2").value;
			side1 = parseInt(side2);
			//rectangle.length = side2;
			rectangle.side[1] = side2;

	var perimeter = rectangle.perimeter();
	var perimeterSpan = 
		document.getElementById("perimeter");
	perimeterSpan.innerHTML = perimeter;
	return 0;
}

function getArea() {
	alert("in getArea")
	return 0;
}