#include <iostream>

using namespace std;

class Student {
private:
    string name;
    int grade;

public:
    Student(string n, int g) {
        name = n;   
        grade = g;  
    }


    string getName() {
        return name;
    }

    int getGrade() {
        return grade;  
    }

   
    void printStudent() {
        cout << "Name: " << getName() << ", Grade: " << getGrade() << endl;
    }
};
void displayTopStudents(Student students[], int numStudents) {
    if (numStudents == 0) {
        cout << "No students available." << endl;
        return;
    }

    int maxGrade = students[0].getGrade();
    for (int i = 1; i < numStudents; ++i) {
        if (students[i].getGrade() > maxGrade) {
            maxGrade = students[i].getGrade();
        }
    }

    cout << "Students with the highest grade (" << maxGrade << "):" << endl;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].getGrade() == maxGrade) {
            students[i].printStudent(); 
        }
    }
}

int main() {
    Student students[] = {
        Student("Alice", 90),
        Student("Kiara", 85),
        Student("William", 92),
        Student("David", 80),
        Student("Evelyn", 92)
    };

    
    int numStudents = sizeof(students) / sizeof(students[0]);

   
    displayTopStudents(students, numStudents);

    return 0;
}
