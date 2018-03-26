function init() {
  var perimeterListener =
    document.getElementById("perimeterButton");
  perimeterListener.addEventListener("click", getPerimeter);

  var areaListener =
    document.getElementById("areaButton");
  areaListener.addEventListener("click", getArea);

  var triListener =
    document.getElementById("triButton");
  triListener.addEventListener("click", getTri);



}
var triangle = {
  //length: 0,
  //width: 0,
  sides: [0,0,0],
   area: function(){
      var p=(this.sides[0]+this.sides[1]+this.sides[2])/2;
      return Math.sqrt(p*((p-this.sides[0])*(p-this.sides[1])*(p-this.sides[2])));
    }, //this is a method
    perimeter: function(){
      return (this.sides[0] + this.sides[1] + this.sides[2]);
    },
     tri: function(){
        if((this.sides[0] + this.sides[1]) <= this.sides[2]){
            return("false");
         }
        if((this.sides[0] + this.sides[2]) <= this.sides[1]){
            return("false");
         }
        if((this.sides[1] + this.sides[2]) <= this.sides[0]){
            return("false");
         }
        else{
            return("true");
         }
     }
 
  };


function getPerimeter() {
    var side1 =
        document.getElementById("side1").value;
        side1 = parseInt(side1);
        //triangle.length = side1;
        triangle.sides[0] = side1;

        var side2 =
            document.getElementById("side2").value;
            side2 = parseInt(side2);
            //triangle.width = side2;
            triangle.sides[1] = side2;

            var side3 =
            document.getElementById("side3").value;
            side3 = parseInt(side3);
            //triangle.width = side2;
            triangle.sides[2] = side3;
            
var perimeter = triangle.perimeter();
  var perimeterSpan =
    document.getElementById("perimeter");
  perimeterSpan.innerHTML = perimeter;
  return 0;
}

function getArea() {
     var side1 =
        document.getElementById("side1").value;
        side1 = parseInt(side1);
        //triangle.length = side1;
        triangle.sides[0] = side1;

        var side2 =
            document.getElementById("side2").value;
            side2 = parseInt(side2);
            //triangle.width = side2;
            triangle.sides[1] = side2;

            var side3 =
            document.getElementById("side3").value;
            side3 = parseInt(side3);
            //triangle.width = side2;
            triangle.sides[2] = side3;
            
var area = triangle.area();
  var areaSpan =
    document.getElementById("area");
  areaSpan.innerHTML = area;
  return 0;
}

function getTri() {
    var side1 =
        document.getElementById("side1").value;
        side1 = parseInt(side1);
        //triangle.length = side1;
        triangle.sides[0] = side1;

        var side2 =
            document.getElementById("side2").value;
            side2 = parseInt(side2);
            //triangle.width = side2;
            triangle.sides[1] = side2;

            var side3 =
            document.getElementById("side3").value;
            side3 = parseInt(side3);
            //triangle.width = side2;
            triangle.sides[2] = side3;
            
var tri = triangle.tri();
  var triSpan =
    document.getElementById("tri");
  triSpan.innerHTML = tri;
  return 0;
}
