#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int id;

public:
    Student(string n, int i) {
        name = n;  
        id = i;   
    }
    string getName() {
        return name;  
    }

    int getId() {
        return id;  
    }

  
    void printStudent() {
        cout << "ID: " << getId() << ", Name: " << getName() << endl;
    }
};

int main() {
    vector<Student> students = {
        Student("Andreea", 101),
        Student("Daria", 111),
        Student("Ana", 123),
        Student("Patricia", 147)
    };

    // Search for a student by name
    string searchName = "Ana";
    bool found = false;
    for (Student& student : students) {
        if (student.getName() == searchName) {
            cout << "Student found: ";
            student.printStudent();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with name " << searchName << " not found." << endl;
    }

    int searchId = 147;
    found = false;
    for (Student& student : students) {
        if (student.getId() == searchId) {
            cout << "Student found: ";
            student.printStudent();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << searchId << " not found." << endl;
    }

    return 0;
}
