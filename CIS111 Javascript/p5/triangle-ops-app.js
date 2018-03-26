 //ratio function
 function is345(a, b, c) {
      if (a % 3 === 0 && b % 4 === 0 && c % 5 === 0 ||
         a % 3 === 0 && c % 4 === 0 && b % 5 === 0 ||
         b % 3 === 0 && a % 4 === 0 && c % 5 === 0 ||
         b % 3 === 0 && c % 4 === 0 && a % 5 === 0 ||
         c % 3 === 0 && a % 4 === 0 && b % 5 === 0 ||
         c % 3 === 0 && b % 4 === 0 && a % 5 === 0)
         return true;
      else;
         return false;
     }
 
 //legal triangle function
 function isTriangle(a, b, c) {
     if ((a + b) > c && (a + c) > b && (b + c) > a) {
         return true;
     } else {
         return false;
     }

 }
 //Area of Triangle function
 function areaOfTriangle(a, b, c) {
     var sum = a + b + c;
     return Math.sqrt(((sum) / 2) * (((sum) / 2) - a) * (((sum) / 2) - b) * (((sum) / 2) - c)).toFixed(2);
 }


 //triangle type
 function getTriangleType(a, b, c) {
     if (a == b && b == c && c == a) {
         return "Equilateral";
     } else if ((a == b) || (b == c) || (c == a)) {
         return "Isosceles";
     } else if (a != b && b != c && c != a) {
         return "Scalene";
     }
 }


 //1. Define the onclick handler
 var display = function() {
     var side1, side2, side3, rslt;
     var a = Number($("#a").val());
     var b = Number($("#b").val());
     var c = Number($("#c").val());



     var btnIndex = $("button").index(this);

     if (btnIndex === 0) {
         //get value entered by user
         side1 = $('#a').val();
         side2 = $('#b').val();
         side3 = $('#c').val();
         rslt = isTriangle(side1, side2, side3);
         $("#tvalDisplay").text(rslt);
     } else if (btnIndex == 1) {
         side1 = Number($('#a').val());
         side2 = Number($('#b').val());
         side3 = Number($('#c').val());
         rslt = areaOfTriangle(side1, side2, side3);
         $("#tvalDisplay").text(rslt);
     } else if (btnIndex == 2) {
         side1 = $('#a').val();
         side2 = $('#b').val();
         side3 = $('#c').val();
         rslt = getTriangleType(side1, side2, side3);
         $("#tvalDisplay").text(rslt);
     } else if (btnIndex == 3) {
         side1 = $('#a').val();
         side2 = $('#b').val();
         side3 = $('#c').val();
         rslt = is345(side1, side2, side3);
         $("#tvalDisplay").text(rslt);
     } else
         $("#tvalDisplay").html("error");



 };

 //2. register the handlers after the page is loaded
 $(document).ready(function() {
     //console.log("ready");

     $("button").on("click", display);


 });