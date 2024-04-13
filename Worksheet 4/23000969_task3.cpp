#include <iostream>
#include <string>

using namespace std;

class School {
private:
    string name;

public:
    School(const string& n) : name(n) {}
    virtual ~School() {}

    virtual void show() const {
        cout << "School name: " << name << endl;
    }
};

class Programming : virtual public School {
private:
    int numProgrammingCourses;

public:
    Programming(const string& n, int numCourses) : School(n), numProgrammingCourses(numCourses) {}

    void show() const override {
        School::show();
        cout << "Number of Programming courses: " << numProgrammingCourses << endl;
    }
};

class Network : virtual public School {
private:
    int numNetworkCourses;

public:
    Network(const string& n, int numCourses) : School(n), numNetworkCourses(numCourses) {}

    void show() const override {
        School::show();
        cout << "Number of Network courses: " << numNetworkCourses << endl;
    }
};

class Student : public Programming, public Network {
private:
    string studentName;
    int studentCode;

public:
    Student(const string& schoolName, const string& name, int code, int numProgCourses, int numNetCourses)
        : School(schoolName), Programming(schoolName, numProgCourses), Network(schoolName, numNetCourses),
          studentName(name), studentCode(code) {}

    void show() const override {
        cout << "Student name: " << studentName << endl;
        cout << "Student code: " << studentCode << endl;
    }
};

int main() {
    Student s("TBC", "Santosh", 100, 7, 8);
    School& p = s;
    p.show();

    return 0;
}
