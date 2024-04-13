#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct Employee{
    char name[150];
    int taxNum;
    float salary;
};

int main(){
    ifstream inputFile("test.bin", ios::binary);
    if (!inputFile) {
        cout << "Error: Unable to open file." << endl;
        return 1;
    }

    ofstream outputFile("data.bin", ios::binary);
    if (!outputFile) {
        cout << "Error: Unable to create file." << endl;
        inputFile.close();
        return 1;
    }

    float amt;
    cout << "Enter the minimum salary amount: ";
    cin >> amt;

    struct Employee employees;
    float totalSalary = 0;
    int count = 0;

    while (inputFile.read(reinterpret_cast<char*>(&employees), sizeof(employees))) {
        if (employees.salary > amt) {
            outputFile.write(reinterpret_cast<char*>(&employees), sizeof(employees));
            totalSalary += employees.salary;
            count++;
        }
    }

    inputFile.close();
    outputFile.close();

    if (count == 0) {
        cout << "No employees found with salary greater than " << amt << endl;
    } else {
        cout << "Data written to data.bin successfully." << endl;
        cout << "Average salary of employees: " << (totalSalary / count) << endl;
    }

    return 0;
}

