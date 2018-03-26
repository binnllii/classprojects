#include "student.h"

//implement the required 3 functions here

void Student::print() const
{
    cout << id << '\t' << gpa << endl;
}

Student::Student(const char initId[], double gpa)
{
    strcpy(id ,initId);
    this->gpa = gpa;
    
    return;
    
    
    
    

}

bool Student::isLessThanByID(const Student& aStudent) const
{
    
                    
    if(strcmp(id, aStudent.id) < 0)
    {
    return true;
    }
    return false;
}
           
bool Student::isLessThanByGpa(const Student& aStudent) const
{
                    
                    
    if(gpa < aStudent.gpa)
    {
        
    return true;
    }
    return false;
}