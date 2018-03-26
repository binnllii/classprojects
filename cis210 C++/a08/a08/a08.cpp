// sources: http://www.chegg.com/homework-help/questions-and-answers/need-help-quickly-problem-code-believe-need-someone-plug-complier-post-screenshot-output-p-q5203944
//  main.cpp
//  a08
//
//  Created by Bin Li on 5/24/16.
//  Copyright © 2016 Bin Li. All rights reserved.
//

/*
A company hired 10 temporary workers who are paid hourly and you are given a
data file that contains the last name of the employees, the number of hours each
employee worked in a week, and the hourly pay rate of each employee.//////////////////////////////////////////
 You are asked to write a program that computes each employee’s weekly pay, and the
average salary of all the workers. The program then outputs the weekly pay of
each employee, the average weekly pay, and the names of all the employees
whose pay is greater than or equal to the average pay. If the number of hours
worked in a week is more than 40 hours, then the pay rate for the hours over 40 is
1.5 times the regular hourly rate. Use two parallel arrays: a one dimensional array
to store the names of the employees, and a two dimensional array of 10 rows and
3 columns to store the number of hours an employee worked in a week, the hourly
pay rate and the weekly pay. Your program must contain at least the following
functions:
a.A function to read the data from the file into the arrays.
b.A function to determine the weekly pay.
c.A function to output the names of all the employees whose pay is greater
than or equal to the average weekly pay.
//d.A function to output each employee’s data.*/



#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const int ROWS = 10;
const int COLUMNS = 3;

//function calls
void readFile (ifstream &, string[], double[][COLUMNS]);
void weeklyPay (string[],double [][COLUMNS]);
void avgWeeklyPay (string[], double[][COLUMNS]);
void output (string[], double[][COLUMNS]);

//main function
int main()
{
    string lastNames[ROWS];
    
    double matrix[ROWS][COLUMNS];
    
    ifstream inFile;
    
    inFile.open("/Users/BinLi/Desktop/cis210/a08/a08/data.txt"); //get input from file
    
    readFile(inFile, lastNames, matrix);
    cout << endl;
    
    weeklyPay(lastNames, matrix);
    cout << endl;
    
    output(lastNames, matrix);
    
    return 0;
}

//reads the file
void readFile(ifstream& inFile, string lastNames[], double matrix[][COLUMNS])
{
    for(int i = 0; i < ROWS; i++)
    {
        inFile >> lastNames[i]; // get input from the file
        for(int c = 0; c < COLUMNS - 1; c++)
        {
            inFile >> matrix[i][c];
        }
        matrix[i][2] = 0;
    }
}

//calculates weekly pays
void weeklyPay(string lastNames[], double matrix[][COLUMNS])
{
    cout << "   Weekly Pay     " << endl;
    for(int i = 0; i < ROWS; i++)
    {
        
        if(matrix[i][0] > 40)
            matrix[i][2] = matrix[i][0] * matrix[i][1] + 1.4 * (matrix[i][0] * matrix[i][1]);
        
        else
            matrix[i][2] = matrix[i][0] * matrix[i][1];
        cout << left << setw(10) << lastNames[i] << setw(10) << matrix[i][2] << endl;
    }
}

//calculates avg weekly pay
void avgWeeklyPay(string lastNames[], double matrix[][COLUMNS])
{
    
    double totalPay = 0;
    for(int r = 0; r < ROWS; r++)
        totalPay += matrix[r][2];
    
    cout << "Names of Employees whose pay is Greater Than or equal to average weekly pay" <<endl;
    cout << "Average Weekly Pay :$" << totalPay / ROWS << endl;
    
    for(int colIndex = 0; colIndex < ROWS; colIndex++)
        if(matrix[colIndex][2] > totalPay / ROWS)// divide by rows
        cout << left << setw(10) << lastNames[colIndex] << " " << left << setw(8) << matrix[colIndex][2] << " " << endl;
}


//outputs information
void output(string lastNames[], double matrix[][COLUMNS])
{
    cout << "Name" << setw(10) << "Hours" << setw(10) << "Pay Rate" << endl;
    for(int r = 0; r < ROWS; r++)
    {
        cout << left << setw(10) << lastNames[r] << " ";
        for(int c = 0; c < COLUMNS; c++)
        {
            cout << left << setw(10) << matrix[r][c] << " ";
        }
        cout << endl;
    }
}





































//MY WORK

//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <string>
//using namespace std;
//
////constants
//const int CAP = 100;
//
////need infile name hour salary
//void openFile(ifstream &inFile);
//int readData(ifstream &inFile, string names[], int salary[], int hours[]);
////void weeklyPay(int size, string names[], int salary, int hours[]);
//void greaterAverage();
//void output();
//
//
//int main()
//{
//    string names[CAP];
//    int salary[CAP] = {0};
//    int hours[CAP] = {0};
//    int size = 0;
//    ifstream inFile;
//
//    openFile(inFile);
//
//    size = readData(inFile, names, salary, hours);
//    cout << size;
//    
//
//    return 0;
//
//
//}
//void openFile(ifstream &inFile)
//{
//    inFile.open("/Users/BinLi/Desktop/cis210/a08/a08/data.txt");
//    if(!inFile)
//    {
//        cout << "File did not open! Program terminating!!";
//        exit(0);
//    }
//}
//
//
//
//int readData(ifstream &inFile, string names[], int salary[],double hours[])
//{
//
//    int size = 0;
//    double payInfo[10][3];
//    
//    while(!inFile.eof())
//            {
//                inFile >> names[size] >> salary[size] >> hours[size];
//                size++;
//        
//            }
//        while(!inFile.eof())
//        {
//            inFile >> names[size];
//            inFile >> payInfo[size][2];   //this will read number of hours worked;
//            payInfo[size][2] = payInfo[size][2] * 7;  //to calculate hours per week.
//            inFile >> payInfo[size][1];   //this will read hourly pay rate
//            payInfo[size][1] = payInfo[size][1] * payInfo[size][2];  //this will calculate weekly payrate and store.
//            size++;
//        }
//    return size;
//}













































//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <string>
//using namespace std;
//
////functions
//void openFile(ifstream &inFile);
////int readData(ifstream &inFile, string names[], int salary[], int hours[]);
//void calculateTotal(int size, string names[], int salary[], int hours[]);
//
//
//const int CAP = 100;
//
//
//int main()
//{
//    string names[CAP];
//    int salary[CAP] = {0};
//    int hours[CAP] = {0};
//    int size = 0;
//    
//    ifstream inFile;
//    openFile(inFile);
//
////    inFile >> names >> salary >> hours;
////    cout << names << salary << hours;
//    
//    
////    size = readData(inFile, names, salary, hours);
////    cout << size;
//    calculateTotal(size, names, salary, hours);
//    
//
//}
//
//// works
//void openFile(ifstream &inFile)
//{
//    
//    inFile.open("/Users/BinLi/Desktop/cis210/a08/a08/data.txt");
//    if(!inFile)
//    {
//        cout << "File did not open! Program terminating!!";
//        exit(0);
//    }
//}
//
////int readData(ifstream &inFile, string names[], int salary[], int hours[])
////{
////    int size = 0;
////    while(!inFile.eof())
////    {
////        inFile >> names[size] >> salary[size] >> hours[size];
////        size++;
////    }
////    return size;
////}
//
//
//void calculateTotal(int size, string names[], int salary[], int hours[])
//{
//   
//    for(int i = 0; i < 10; i++)
//    {
//        cout << names[i] << salary[i] << hours[i];
//    }
//}




















//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <string>
//using namespace std;
//
////constants
//const int CAP = 100;
//
////need infile name hour salary
//void openFile(ifstream &inFile);
//int readData(ifstream &inFile, string names[], int salary[], int hours[]);
//void weeklyPay(int size, string names[], int salary, int hours[]);
//void greaterAverage();
//void output();
//
//
//int main()
//{
//    string names[CAP];
//    int salary[CAP] = {0};
//    int hours[CAP] = {0};
//    int size = 0;
//    ifstream inFile;
//    
//    openFile(inFile);
//   
//    size = readData(inFile, names, salary, hours);
//    
//    //weeklyPay(size, names, salary, hours);
//
//   
//   return 0;
//
//    
//   
//}
//void openFile(ifstream &inFile)
//{
//    //"/Users/BinLi/Desktop/cis210/lab3/lab3/Ch3_Ex6Data.txt"
//    //inFile.open("/Users/BinLi/Desktop/cis210/a08/a08/data.txt");
//    inFile.open("/Users/BinLi/Desktop/cis210/a08/a08/data.txt");
//   
//    if(!inFile)
//    {
//        cout << "File did not open! Program terminating!!";
//        exit(0);
//    }
//}
//
//int readData(ifstream &inFile, string names[], int salary[], int hours[])
//{
//   
//   int size = 0;
//   while(!inFile.eof())
//   {
//       inFile >> names[size] >> salary[size] >> hours[size];
//       cout << names[size] << salary[size] << hours[size];
//       size++;
//       
//   }
//   return size;
//}
//
//
//void weeklyPay(int size, string names[], int salary[], int hours[])
//{
//   int totalS = 0, totalH = 0;
//   int weeklyP;
//   for(int i = 0; i < size; i++)
//   
//       totalS += salary[i];
//   
//   for(int i = 0; i < size; i++)
//   
//       totalH += hours[i];
//   
//   for(int i = 0; i < size; i++)
//   {
//       weeklyP = totalH * totalS;
//       cout << weeklyP;
//   }
//   
//   
//}















//#include <iostream>
//using namespace std;
//
////constants
//const int STDS = 3;
//const int QZS = 2;
//
//int main()
//{
//    int scores[STDS][QZS];
//    int total = 0, average = 0;
//    
//    for(int i = 0; i < STDS; i++)
//    {
//        cout << "Enter scores for student #" << i << ":" << endl;
//        for(int j = 0; j < QZS; j++)
//            cin >> scores[i][j];
//    }
//    
//    //print the scores
//    for(int i = 0; i < STDS; i++)
//    {
//        cout << "Scores for student #" << i << ":" << endl;
//        for(int j = 0; j < QZS; j++)
//            cout << scores[i][j] << " ";
//        cout << endl;
//    }
//    //average for every student
//    for(int i = 0; i < STDS; i++)
//    {
//        total = 0;
//        for(int j = 0; j < QZS; j++)
//        {
//            total += scores[i][j];
//        }
//        average = total / QZS;
//        cout << "Average for student " << i << "  = " << average << endl;
//    }
//    return 0;
//}