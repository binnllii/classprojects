var car = {
	make: "Volkswagon",
	model: "Jetta",
	year: "2015",
	speed: "50",
	description:function() {
	return car.year + " " + car.make + " " + car.model;
}
};

function isSpeedOk(speedlimit){
	if(speedlimit >= 40 && speedlimit <= 60)
		return("True");
	else;
		return("False");
}


var triangle=
{
    sides:[3,4,5],
    isTriangle: function()
    {
        if(this.sides[0] > this.sides[1] && this.sides[0] > this.sides[2])
        {
            if(this.sides[1] + this.sides[2] > this.sides[0])
            {
                return true;
            }
        }
        if(this.sides[1] > this.sides[0] && this.sides[1] > this.sides[2])
        {
            if(this.sides[0] + this.sides[2] > this.sides[1])
            {
            return true;
            }
        }
        if(this.sides[2] > this.sides[1] && this.sides[2] > this.sides[0])
        {
            if(this.sides[1] + this.sides[0] > this.sides[2])
            {
            return true;
            }
        }
        else
        {
        return false;
        }
    },
    perimeter:function(){return this.sides[0]+this.sides[1]+this.sides[2];},
    area:function(){return (.5*(this.sides[0]*this.sides[1]));}
};
triangle.perimeter();
triangle.area();
triangle.isTriangle();







var person = {

    firstName: "Benny",
    lastName: "Lee",
    birthday: new Date ('02, 14 ,1995'),
    facebookPage: "www.facebook.com/thegreathoudini/",

isValidPage: function(){
	var facebook = new RegExp("www.facebook.com/thegreathoudini");
	return facebook.test(this.facebookPage);
}

fullName: function() {
        return person.firstName + " " + person.lastName;
},



age: function()  {
    today = new Date();
    var currentAge = today - this.birthday;
    var millPerYear = 1000*60*60*24*365.25;
    return (currentAge/millPerYear);

    },
};