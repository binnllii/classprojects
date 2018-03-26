//sources: "http://www.cplusplus.com/forum/general/191035/"

/*Write	C++	statements	to	do	the	following:
 a) Define	an	enum	type,	birdType,	with	the	values	PEACOCK,	SPARROW,
 CANARY,	PARROT,	PENGUIN,	OSTRICH,	EAGLE,	CARDINAL,	and
 HUMMINGBIRD.
 b) Declare	a	variable	bird	of	the	type	birdType.
 c) Assign	CANARY	to	the	variable	bird.
 d) Advance	bird	to	the	next	value	in	the	list.
 e) Output	the	value	of	the	variable	bird.
 f) Input	a	value	(from	the	user)	in	the	variable	bird.
 
 That means you have to read an input from the user into the enum variable. Give the user the choice of the birds, and ask the user to pick one and enter into the variable.
*/



#include <iostream>
#include <string>

//declare enum
enum birdtype {birdMin = 0, PEACOCK = birdMin, SPARROW, CANARY, PARROT, PENGUIN, OSTRICH, EAGLE, CARDINAL, birdMax = CARDINAL + 1, HUMMINGBIRD = birdMax};

//set string bird names
const std::string bird_name[] = {"PEACOCK", "SPARROW", "CANARY", "PARROT", "PENGUIN", "OSTRICH", "EAGLE", "CARDINAL", "HUMMINGBIRD"};


void display_birds() //function to display a list of birds
{
    for(int i = birdMin; i <= birdMax; i++) //creates the list of birds
    {
        std::cout << i << " = " << bird_name[birdtype(i)] << std::endl;
    }
}


std::string bird_to_string(birdtype bird)
{
    if(bird >= birdMin && bird <= birdMax) return bird_name[bird];
    else return "UNKNOWN";
}

int main()
{
    birdtype bird = CANARY ; //Declare a variable CANARY to bird
    bird = static_cast <birdtype> (bird + 1); //make bird variable + 1
    std::cout << bird_to_string(bird) << std::endl; //output bird
    
    display_birds() ; //Display all the bird types
    
    std::cout << "\nEnter a number from (" << PEACOCK << " - " << HUMMINGBIRD << ") that correspond to the bird type: ";
    int num = birdMin;
    std::cin >> num; //Ask for user input number, that corresponds to bird type.
    if (num >= birdMin && num <= birdMax) //if the number is within the range of the enumeration
    {
        bird = birdtype(num); //Comvert it to the bird using the number
        std::cout << "Birdtype is " << bird_to_string(bird) << "." << std::endl;
    }
    
    else std::cout << num << "Number does not correspond to birdtype\n"; // else print out number doesnt correspond
}















//#include <iostream>
//#include <fstream>
//#include <string>
//#include <iomanip>
//#include <istream>
//
//using namespace std;
////
//
//enum birdType {PEACOCK, SPARROW, CANARY, PARROT, PENGUIN, OSTRICH, EAGLE, CARDINAL, HUMMINGBIRD};
//
//string stringToBird(birdType birdy);
//
//int main()
//{
//    birdType bird;
//    bird = CANARY; //set bird to equal canary
//    bird = static_cast <birdType> (bird + 1); //make bird variable + 1 on the switch statement
//    cout << stringToBird(bird) << endl; //print bird
//    cout << "Enter one of these bird names: PEACOCK, SPARROW, CANARY, PARROT, PENGUIN, OSTRICH, EAGLE, CARDINAL, HUMMINGBIRD: "; //ask for user input
////    bird = static_cast <birdType> (bird);
////    cin >> bird;
////    cout << stringToBird(bird);
//
//
//
//
//}
//
//string stringToBird(birdType birdy)
//{
//    //switch statement for he birds
//    switch (birdy)
//    {
//        case PEACOCK:
//            return "peacock";
//        case SPARROW:
//            return "sparrow";
//        case CANARY:
//            return "canary";
//        case PARROT:
//            return "parrot";
//        case PENGUIN:
//            return "penguin";
//        case OSTRICH:
//            return "ostrich";
//        case EAGLE:
//            return "eagle";
//        case CARDINAL:
//            return "cardinal";
//        case HUMMINGBIRD:
//            return "hummingbird";
//
//    }
//}