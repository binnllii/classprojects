

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const int ROWS = 10;
const int COLUMNS = 2;


void readFile(ifstream& inFile, string lastNames[], double matrix[][COLUMNS]);
void printFile(string foodName[], double matrix[][COLUMNS]);
void total(string foodName[], double matrix[][COLUMNS]);

int main()
{
    double tots;
    ifstream inFile;
    
    inFile.open("/Users/BinLi/Desktop/cis210/RestaurantApp/RestaurantApp/restaurant.txt");

    string foodName[ROWS];
    
    double matrix[ROWS][COLUMNS];
    
    readFile(inFile, foodName, matrix);
    printFile(foodName, matrix);
    total(foodName, matrix);
   
    
}




void readFile(ifstream& inFile, string foodName[], double matrix[][COLUMNS])
{
    for(int i = 0; i < ROWS; i++)
    {
        inFile >> foodName[i];// get input from the file
        for(int c = 0; c < COLUMNS - 1; c++)
        {
            inFile >> matrix[i][c];
        }
    }

}

void printFile(string foodName[], double matrix[][COLUMNS])
{
    cout << "What would you like?" << endl;
    for(int colIndex = 0; colIndex < ROWS; colIndex++)
            cout << left << setw(4) << colIndex + 1 << setw(20) << foodName[colIndex] << "$" << left << setw(15) << fixed << setprecision(2) << matrix[colIndex - 1][2] << " " << endl;

}


void total(string foodName[], double matrix[][COLUMNS])
{
    double total = 0.0;
    int item;
    cout << "What item would you like (Enter a number) or enter q to find the total and pay?";
    cin >> item;
    while(item != 'q')
    {
        if((item = '1'))
            total = total + matrix[0][2];
        if((item = '2'))
            total = total + matrix[1][2];
        if((item = '3'))
            total = total + matrix[2][2];
        if((item = '4'))
            total = total + matrix[3][2];
        if((item = '5'))
            total = total + matrix[4][2];
        if((item = '6'))
            total = total + matrix[5][2];
        if((item = '7'))
            total = total + matrix[6][2];
        if((item = '8'))
            total = total + matrix[7][2];
        if((item = '9'))
            total = total + matrix[8][2];
    }
    cout << total;
}

