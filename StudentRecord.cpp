#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Student {
    int rollNumber;
    string name;
    int marks;
};
int main() {
    Student students[100];
    int studentCount = 0;
    ifstream file("students.txt");
    if(!file.is_open()){
        cout<<"Cannot open file."<<endl;
    }
    while(file>>students[studentCount].rollNumber >> students[studentCount].name >> students[studentCount].marks){
        studentCount++;
        if(studentCount>100){
            break;
        }
    }
    cout << "Enter details for a new student: "<<endl;
    Student newStudent;
    cout << "Roll Number: "<<endl;
    cin >> newStudent.rollNumber;
    cin.ignore();  
    cout << "Name: "<<endl;
    getline(cin, newStudent.name);
    cout << "Marks (0-100): "<<endl;
    cin >> newStudent.marks;
    if(newStudent.marks < 0 || newStudent.marks > 100){
        cout<<"Error: Marks should be between 0 and 100."<<endl;
    }
    else{
        bool rollDuplicate = false;
        for (int i = 0; i < studentCount; ++i) {
            if (students[i].rollNumber == newStudent.rollNumber) {
                cout << "Error: Roll number already exists." << endl;
                rollDuplicate = true;
                break;
            }
        }
        if (!rollDuplicate && studentCount < 100) {
            students[studentCount] = newStudent;
            studentCount++;
            cout << "New student added successfully.\n";
        } else if (studentCount >= 100) {
            cout << "Error: Maximum student limit reached.\n";
        }
    }
    ofstream file1("students.txt");
    if (!file1.is_open()) {
        cout << "Error: Could not open the file for writing." << endl;
        return 1;
    }
    for (int i = 0; i < studentCount; ++i) {
        file1 << students[i].rollNumber << " " << students[i].name << " " << students[i].marks << endl;
    }
    file1.close();
    return 0;
}
