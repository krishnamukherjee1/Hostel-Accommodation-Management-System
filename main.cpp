#include <iostream>
#include "include/Student.h"

using namespace std;

int main()
{
    Student student1;

    student1.setName("Krishna Mukherjee");
    cout << "Student Name: " << student1.getName() << endl;
    
    cout << "=====================================\n";
    cout << " Hostel Accommodation Management System\n";
    cout << " Version 1.1\n";
    cout << "=====================================\n";

    return 0;
}