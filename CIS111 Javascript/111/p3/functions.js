function iseven(num)
{
	if(num % 2 == 0)
		return true; 
	if(num % 2 == 1)
		return false;

}

function kindofday(day)
{
	if(day == "sunday"){
		return "weekend";
	}
	else if(day == "saturday"){
		return "weekend";
	}
	else if(day == "friday"){
		return "weekday";
	}
	else if(day == "thursday"){
		return "weekday";
	}
	else if(day == "wednesday"){
		return "weekday";
	}
	else if(day == "tuesday"){
		return "weekday";
	}
	else if(day == "monday"){
		return "weekday";
	}
	else{
		return "not a day";
	}
}

function count(num)
{
	var s = " ";
	for(var i = 1; i <= num; i++)
		if(i == num)
		{
			s = s + i;
		}
		else
		{
			s = s + i + ", ";
		}
return(s)
}

function countChange(q, d, n, p)
{
	quarter = .25
	dime = .10
	nickel = .05
	penny = .01

	money = ((quarter * q) + (dime * d) + (nickel * n) + (penny * p))

return("$" + money)
}