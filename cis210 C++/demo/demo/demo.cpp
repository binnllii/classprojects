
/*Write	C++	statements	to	do	the	following:
 a) Define	an	enum	type,	birdType,	with	the	values	PEACOCK,	SPARROW,
 CANARY,	PARROT,	PENGUIN,	OSTRICH,	EAGLE,	CARDINAL,	and
 HUMMINGBIRD.
 b) Declare	a	variable	bird	of	the	type	birdType.
 c) Assign	CANARY	to	the	variable	bird.
 d) Advance	bird	to	the	next	value	in	the	list.
 e) Output	the	value	of	the	variable	bird.
 f) Input	a	value	(from	the	user)	in	the	variable	bird.*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

enum birdType {PEACOCK, SPARROW, CANARY, PARROT, PENGUIN, OSTRICH, EAGLE, CARDINAL, HUMMINGBIRD};

string stringToBird(birdType birdy);

int main()
{
    birdType bird;
    birdType jay;
    bird = CANARY;
    bird = static_cast <birdType> (bird + 1);
    cout << stringToBird(bird) << endl;
    cout << "Enter a bird name: ";
   // jay = static_cast <birdType> (jay);
   // cin >> jay;
}

string stringToBird(birdType birdy)
{
    switch (birdy)
    {
        case PEACOCK:
            return "peacock";
        case SPARROW:
            return "sparrow";
        case CANARY:
            return "canary";
        case PARROT:
            return "parrot";
        case PENGUIN:
            return "penguin";
        case OSTRICH:
            return "ostrich";
        case EAGLE:
            return "eagle";
        case CARDINAL:
            return "cardinal";
        case HUMMINGBIRD:
            return "hummingbird";
        
    }
}

