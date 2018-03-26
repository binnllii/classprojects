var p = {
     "firstName": "John",
     "lastName" : "Smith",
     "age"      : 25,

     "address"  :
     {
         "streetAddress": "21 2nd Street",
         "city"         : "Portland",
         "state"        : "OR",
         "postalCode"   : "90021"
     },
     "phoneNumber":
     [
         {
           "type"  : "home",
           "number": "212.555.1234"
         },
         {
           "type"  : "fax",
           "number": "646.555.4567"
         },
         {
           "type"  : "work",
           "number": "541.502.1212"
         },
        {
           "type"  : "mobile",
           "number": "541.406.8765"
         }
     ]
 };
var getAddress = function()
  {
    return p.address.streetAddress + ", " + p.address.city + ", " + p.address.state + " " + p.address.postalCode;
  };

var getTelNums = function(){
var result = "";
var n = p.phoneNumber.length;
//get all the telephone numbers
for (var i = 0; i < n; ++i){
  result = result + p.phoneNumber[i].number + " ";
}
  return result;
};
// var getTelNum = function(){
//     var results = "";
//     var n = p.phoneNumber.length;
//     for(var i = 0, i < n, ++i){
//       result = result + p.phoneNumber[i].number + " "
//   }
//     return result;
//  	function getTelNums()
// 	{
 //     return p.phoneNumber[0].number + " " + p.phoneNumber[1].number + " " + p.phoneNumber[2].number + " " + p.phoneNumber[3].number;
 //			
 //	}
 	


 

