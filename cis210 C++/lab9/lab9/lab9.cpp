//
//  lab9.cpp
//  lab9
//
//  Created by Bin Li on 6/1/16.
//  Copyright © 2016 Bin Li. All rights reserved.
//
/*Write	a	program	that	reads	students’	names	followed	by	their	test	scores	from	the	given	input	file.		The
program	should	output	to	a	file,	output.txt,	each	student’s	name	followed	by	the	test	scores	and	the relevant	grade.
Student	data	should	be	stored	in	a	struct	variable	of	type	StudentType,	which	has	four	components:
studentFName and	studentLName	of	type	string,	testScore	of	type	int	and	grade	of	type	char.		Suppose
that	the	class	has	20	students.		Use	an	array	of	20	components	of	type	StudentType.		Your	program	must
contain	at	least	the	following	functions:
 
1. A	function	to	read	the students’	data	into	an	array.
2. A	function	to	assign	the	relevant	grade	to	each	student.

Your	program	should	output	each	student’s	name	in	this	form:	last	name	followed	by	a	comma,
followed	by	a	space,	followed	by	the	first	name;	the	name	must	be	left	justified.		Moreover,	other	than
declaring	the	variables	and	opening	the	input	and	output	files,	the	function	main	should	only	be	a
collection	of	function	calls.*/




#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


// namespace
using namespace std;

// constant
const int numStudents = 20;

// struct studentType
struct studentType
{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

//function initiations
void getData(ifstream &inFile, studentType studentL[], int listSize);
void calculateGrade(studentType studentL[], int listSize);
void outputResult(ofstream& outFile, const studentType studentL[], int listSize);
void openFile(ifstream &inFile, ofstream &outFile);

//input output file
int main()
{
    //function calls
    ifstream inFile;
    ofstream outFile;
    studentType studentList[numStudents];
    openFile(inFile, outFile);
    getData(inFile, studentList, numStudents);
    calculateGrade(studentList, numStudents);
    outputResult(outFile, studentList, numStudents);
    system("PAUSE");
    return 0;
}

//opens the file and inputs into file
void openFile(ifstream &inFile, ofstream &outFile)
{
    inFile.open("/Users/BinLi/Desktop/cis210/lab9/lab9/name.txt");
    if (!inFile)
    {
        cerr << "Error opening the file. Program terminate!";
        exit(1);
    }
    
    //outFile
    outFile.open("/Users/BinLi/Desktop/cis210/lab9/lab9/output.txt");
    if (!outFile)
    {
        cerr << "Error linking to file. Program terminate!";
        exit(1);
    }

}

//get data
void getData(ifstream& inFile, studentType studentL[], int listSize)
{
    for (int i = 0; i < listSize; i++)
        inFile >> studentL[i].studentFName >> studentL[i].studentLName >> studentL[i].testScore;
}




//calculates grade
void calculateGrade(studentType studentL[], int listSize)
{
    
    for (int i = 0; i < listSize; i++)
        if (studentL[i].testScore >= 90)
            studentL[i].grade = 'A';
        else if (studentL[i].testScore >= 80)
            studentL[i].grade = 'B';
        else if (studentL[i].testScore >= 70)
            studentL[i].grade = 'C';
        else if (studentL[i].testScore >= 60)
            studentL[i].grade = 'D';
        else
            studentL[i].grade = 'F';
    
    
}


// output results
void outputResult(ofstream& outFile, const studentType studentL[], int listSize)
{
    outFile << left << setw(23) << "Student Name " << setw(10) << "Test Score" << setw(8) << right << "Grade" << endl;
    
    for (int i = 0; i < listSize; i++)
        outFile << left << setw(24) << studentL[i].studentLName + ", " + studentL[i].studentFName << right << " " << setw(4) << studentL[i].testScore
        << setw(9) << " " << studentL[i].grade << endl;
}
















//
//#include <iostream>
//#include <fstream>
//#include <iomanip>
//#include <string>
//
//using namespace std;
//
//struct StudentType
//{
//    string studentFname;
//    string studentLname;
//    int testScore;
//    char grade;
//};
//
//
//void openFile(ifstream &inFile);
//int dataToArray(ifstream &inFile, StudentType studentList[]);
//void outputDataGrade(StudentType studentList[]);
//
//
////relavantGrade
//
//int main()
//{
//    int size = 0;
//    StudentType students[20];
//    string name, lname;
//    
//    ifstream inFile;
//    openFile(inFile);
//    size = dataToArray(inFile, students);
//    outputDataGrade(students);
//    
//    
//    
//    
//    
// }
//
//
//
////opens the file
//void openFile(ifstream &inFile)
//{
//    inFile.open("/Users/BinLi/Desktop/cis210/lab9/lab9/name.txt");
//    if (inFile.fail())
//    {
//        cerr << "Error opening the file";
//        exit(1);
//    }
//}
//
////returns the number of names in the list
//int dataToArray(ifstream &inFile, StudentType studentList[])
//{
//    int size = 0;
//    while(!inFile.eof())
//    {
//        inFile >> studentList[size].studentFname >> studentList[size].studentLname >> studentList[size].testScore;
//        size++;
//    }
//    return size;
//}
//
//
//
//void outputDataGrade(StudentType studentList[])
//{
//    
//    for (int i = 0; i < 20; i++)
//    {
//        char grade;
//        if(studentList[i].testScore >= 90)
//            grade = 'A';
//        else if (studentList[i].testScore >= 80)
//            grade = 'B';
//        else if (studentList[i].testScore >= 70)
//            grade = 'C';
//        else if (studentList[i].testScore >= 60)
//            grade = 'D';
//        else if (studentList[i].testScore < 59)
//            grade = 'F';
//        
//        cout << setw(12) << left << studentList[i].studentFname
//        << setw(12) << studentList[i].studentLname << setw(6) << studentList[i].testScore << setw(6) << grade << endl;
//    };
//
//}
