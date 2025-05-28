#include "student.h"

Student::Student() {
    name = "";
    score = 0;
    grade = 'F';
}

Student::Student(string name, int score) : name(name), score(score) {
    char temp[] = { 'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A' };
    int index = score / 10;
    if (index > 10) index = 10;
    grade = temp[index];
}

Student::~Student() {
}

void Student::print() {
    cout << setw(12) << left << name;
    cout << setw(8) << right << score;
    cout << setw(8) << right << grade << endl;
}
