//
//  main.cpp
//  a04
//
//  Created by Bin Li on 4/29/16.
//  Copyright © 2016 Bin Li. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main ()
{
    //variables
    string name, college;
    string inputFileName;
    int males = 0, malec = 0, females = 0, femalec = 0, ccscore = 0, cccount = 0, unscore = 0, uncount = 0;
    //stream vars
    ifstream inputFile;
    ofstream outputFile;
    
    //"/Users/BinLi/Desktop/cis210/lab3/lab3/Ch3_Ex6Data.txt
    cout << "Input file name: ";
    cin >> inputFileName;
    
    // Open the input file.
    inputFile.open(inputFileName.c_str());	// Need .c_str() on a mac to convert a C++ string to a C-style string
    
    //display error msg in case of invalid path
    if ( !inputFile.is_open())
    {
        cout << "Unable to open input file." << endl;
        exit(1);
    }
    //when it isnt the end of file, store the following information
    while (inputFile.peek() != EOF)
    {
        char gender;
        int score;
        string college;
        inputFile >> name >> gender >> college >> score;
        cout << left << setw(14) << name << setw(6) << gender << setw(6) << college << setw(6) << score << endl;
        //avg for M and F
        if (gender == 'M')
        {
            males += score;
            malec++;
        }
        else if(gender == 'F')
        {
            females += score;
            femalec++;
        }
        //avg for cc and Univ
        if (college == "CC")
        {
            ccscore += score;
            cccount++;
        }
        else if(college == "UN")
        {
            unscore += score;
            uncount++;
            
        }
    }
    
    
    //Print averages using the stored information
    cout << fixed << showpoint << setprecision(2);
    cout << "Average score of Males is: " << static_cast<double>(males) / malec << endl;
    cout << "Average score of Females is: " << static_cast<double>(females) / femalec << endl;
    cout << "Average score of Community Colleges are: " << static_cast<double>(ccscore) / cccount << endl;
    cout << "Average score of Universities are: " << static_cast<double>(unscore) / uncount << endl;
    cout << "Average of all scores is: " << static_cast<double>(unscore + ccscore) / 12 << endl;
    
    cout << "\nEnd of file reached\n" << endl;
    
}

