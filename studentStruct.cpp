#include <iostream>
#include <iomanip>
using namespace std;

// Write a C++ program that defines a Student structure containing three fields: a string for the student's name, an integer for 
// their age, and a double for their GPA. In the program, dynamically allocate memory for a single Student using a pointer. Then, 
// use the pointer to assign values to the student's fields. 

struct Student {
    string name;
    int age;
    double gpa;
};

Student* createStudent();
void outputStudent(Student* ptr);

int main() {
    Student* ptr = nullptr;
    
    ptr = createStudent();
    outputStudent(ptr);

    
    return 0;
}

Student* createStudent() {
    Student* ptr = new Student;

    cout << "Enter Student Name: ";
    getline(cin, ptr->name);
    cout << "Enter Student Age: ";
    cin >> ptr->age;
    cout << "Enter Student GPA: ";
    cin >> ptr->gpa;

    return ptr;
}

void outputStudent(Student* ptr) {
    cout << setprecision(1) << fixed;
    cout << "\nStudent: " << endl;
    cout << "Name: " << ptr->name << endl;
    cout << "Age: " << ptr->age << endl;
    cout << "GPA: " << ptr->gpa << endl;
}