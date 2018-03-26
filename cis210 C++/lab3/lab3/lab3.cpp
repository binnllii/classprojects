//enter in kilo return in lb

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;
int main()
{
    double kilo = 0, lb = 0;
    //Prompt user for input
    cout << "Enter persons weight in kilograms: ";
    cin >> kilo;
    while (!cin)
    {
        //reset cin back to the original state
        cin.clear();
        //clear the content of the input buffer or the unwanted information that was entered before
        cin.ignore(100, '\n');
        cout << "Bad input! Please try again: ";
        cin >> kilo;
    }
    lb = kilo * 2.2;
    //output the lbs
    cout << fixed << showpoint << setprecision(2);
    cout << kilo << " kilograms equals " << lb << " pounds." << endl;
    return 0;
}

//take data from a .txt folder and manipulate it then store it in another folder
int main()
{
    //declare the variables
    ifstream inFile;
    ofstream outFile;
    string fname, lname;
    double salary = 0, increase = 0, updatedsalary = 0;
    inFile.open("/Users/BinLi/Desktop/cis210/lab3/lab3/Ch3_Ex6Data.txt");
    outFile.open("/Users/BinLi/Desktop/cis210/lab3/lab3/Ch3_Ex6Output.dat");
    //set to 2 decimal places
    cout << fixed << setprecision(2);
    outFile << fixed << setprecision(2);
    
    //Process the data
    //output the data
    //output into new file
    inFile >> lname >> fname >> salary >> increase;
    updatedsalary = salary * ((increase/100) + 1);
    cout << fname << " " << lname << " " <<  updatedsalary << endl;
    outFile << fname << " " << lname << " " <<  updatedsalary << endl;
    
    inFile >> lname >> fname >> salary >> increase;
    updatedsalary = salary * ((increase/100) + 1);
    cout << fname << " " << lname << " " <<  updatedsalary << endl;
    outFile << fname << " " << lname << " " <<  updatedsalary << endl;
    
    inFile >> lname >> fname >> salary >> increase;
    updatedsalary = salary * ((increase/100) + 1);
    cout << fname << " " << lname << " " <<  updatedsalary << endl;
    outFile << fname << " " << lname << " " <<  updatedsalary << endl;
    inFile.close();
    outFile.close();
    
    return 0;

}


//calculate if the trees will fit along the length of the back yard
const double PI = 3.14159;

int main()
{
    //variables
    double yards = 0, radius = 0, space = 0, circum = 0, areaoftree = 0;
    int trees = 0;
    //ask for inputs
    cout << "Enter the length of your yard: ";
    cin >> yards;
    while (!cin)
    {
        //reset cin back to the original state
        cin.clear();
        //clear the content of the input buffer or the unwanted information that was entered before
        cin.ignore(100, '\n');
        cout << "Bad input! Please try again: ";
        cin >> yards;
    }
    cout << "Enter the radius of the fully grown tree: ";
    cin >> radius;
    while (!cin)
    {
        //reset cin back to the original state
        cin.clear();
        //clear the content of the input buffer or the unwanted information that was entered before
        cin.ignore(100, '\n');
        cout << "Bad input! Please try again: ";
        cin >> radius;
    }
    cout << "Enter the space required in between the fully grown trees: ";
    cin >> space;
    while (!cin)
    {
        //reset cin back to the original state
        cin.clear();
        //clear the content of the input buffer or the unwanted information that was entered before
        cin.ignore(100, '\n');
        cout << "Bad input! Please try again: ";
        cin >> space;
    }
    circum = radius * 2;
    trees = yards / (circum + space);
    areaoftree = PI * pow(radius, 2);
    //return the outputs
    cout << "The number trees that can be grown is: " << trees << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "The total space that will be occupied by the trees is: " << areaoftree * trees << " Square units" << endl;
    
    return 0;
    
    
}
