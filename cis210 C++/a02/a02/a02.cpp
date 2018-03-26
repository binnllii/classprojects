/*
 set variables
 get miles at start
 get miles at the end
 get gallons at the start
 get gallons at the end
 ask for user input
 calculate miles2-mile1 to get the miles traveled
 calculate end - start to get the gallons
 take those 2 and calculate the mpg 
 turn gallons into liters
 turn miles into kilometers
 use those to calculate liters per 100 kilos
 modify so that it also shows liters and kilometers
 1mile = 1.609kms
 1gallon = 3.785liters
*/

#include <iostream>
#include <iomanip>
using namespace std;

const double miletokm = 1.60934;
const double gallontolit = 3.78541;

int main()
{
    //set variables
    double miles1 = 0, miles2 = 0, fuel1 = 0, fuel2 = 0, milesused = 0, fuelused = 0, literused = 0, kilodriven = 0, litperhundred = 0;
    //ask for user input
    cout << "What is your starting odometer milage? ";
    cin >> miles1;
    cout << "What is your ending odometer milage? ";
    cin >> miles2;
    cout << "How many gallons of fuel did your car start with? ";
    cin >> fuel1;
    cout << "How many gallons of fuel did is left in the car after the journey? ";
    cin >> fuel2;
    //calculate the miles traveled and gallons of fuel used
    milesused = miles2 - miles1; //miles traveled
    fuelused = fuel1 - fuel2;  //gallons used
    cout << fixed << showpoint << setprecision(2);
    //output the miles traveled and gallons of fuel used
    cout << "Number of miles traveled: " << milesused << " miles" << endl;
    cout << "Fuel used: " << fuelused << " gallons" << endl;
    cout << "Your car has an estmated " << milesused / fuelused << " miles per gallon." << endl;
    //1gallon = 3.785liters
    //1mile = 1.609kms
    //convert miles to kilometers and gallons to liters
    literused = fuelused * gallontolit;
    kilodriven = milesused * miletokm;
    cout << endl;
    //output kilo driven and liters used
    cout << "Your car traveled " << kilodriven << " kilometers." << endl;
    cout << "Your car used " << literused << " liters of gas." << endl;
    //100 kilo = 235.1889 liters
    //calculate the liters used to drive 100 kilos and output it.
    litperhundred = (literused / kilodriven) * 100;
    cout << "Liters per 100 kilometers: " << litperhundred << endl;
    
    
    return 0;
    
}