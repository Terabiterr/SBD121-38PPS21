#include <iostream>
#include "Student.h"

int main()
{
    Student student1(1, "Smith", "Scottish", 1, 17);
    Student student2(2, "Johnson", "Martinez", 1, 21);
    Student student3(3, "Williams", "Davis", 1, 25);
    cout << student1.ToString() << endl;
    cout << student2.ToString() << endl;
    cout << student3.ToString() << endl;
}
