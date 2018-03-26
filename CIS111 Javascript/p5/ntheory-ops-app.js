var display = function () {


var isDeficient = function(n){
  if(sumOfProperDivisors(n)<n){
    return true;
  }else{
    return false;
  }
};

var sumOfProperDivisors = function(n){
  var sum = 1;
  for(var i = 2; i<n; i++){
    if(n%i==0)
      sum += i;
  }

  return sum;
}

var isPerfect= function(n){
  if(sumOfProperDivisors(n) === n){
    return true;
  }else{
    return false;
  }
};



var isAbundant = function(n){
  if(sumOfProperDivisors(n)>n){
    return true;
  }else{
    return false;
  }
};



var isPrime = function(n){
  if(sumOfProperDivisors(n) === 1){
    return true;
  }else{
    return false;
  }
};



  var x = Number($("#x").val());

  var btnIndex = $("button").index(this);

  if (btnIndex == 0)
    $("#tvalDisplay").text(isDeficient(x));
  else if (btnIndex == 1)
    $("#tvalDisplay").text(isPerfect(x));
  else if (btnIndex == 2)
    $("#tvalDisplay").text(isAbundant(x));
  else if (btnIndex == 3)
    $("#tvalDisplay").text(isPrime(x));
  else
    $("#tvalDisplay").html("error");



};


$(document).ready(function(){
  
  $("button").on("click", display);

});