#include <iostream>
using namespace std;

class Student {
private:
    int code;
    int courses;
    float *grades;

public:
    Student();
    ~Student();
    friend istream& operator>>(istream& in, Student& s);
    friend int operator>(const Student& s1, const Student& s2);
    Student& operator=(const Student&) = delete;
};

Student::Student() : code(0), courses(0), grades(nullptr) {}

Student::~Student() {
    delete[] grades;
}

istream& operator>>(istream& in, Student& s) {
    in >> s.code >> s.courses;
    s.grades = new float[s.courses];
    for (int i = 0; i < s.courses; ++i) {
        in >> s.grades[i];
    }
    return in;
}

int operator>(const Student& s1, const Student& s2) {
    int passedCourses1 = 0, passedCourses2 = 0;
    for (int i = 0; i < s1.courses; ++i) {
        if (s1.grades[i] >= 5) {
            passedCourses1++;
        }
    }
    for (int i = 0; i < s2.courses; ++i) {
        if (s2.grades[i] >= 5) {
            passedCourses2++;
        }
    }
    if (passedCourses1 > passedCourses2) {
        return 1;
    } else if (passedCourses1 < passedCourses2) {
        return 2;
    } else {
        return 3;
    }
}

int main() {
    int i;
    Student s1, s2;
    cout << "Enter information for student 1:" << endl;
    cin >> s1;
    cout << "Enter information for student 2:" << endl;
    cin >> s2;
    i = (s1 > s2);
    if (i == 1) {
        cout << "Student 1 succeeded in more courses." << endl;
    } else if (i == 2) {
        cout << "Student 2 succeeded in more courses." << endl;
    } else {
        cout << "Both students succeeded in the same number of courses." << endl;
    }
    return 0;
}
