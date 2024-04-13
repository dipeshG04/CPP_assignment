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
    struct Employee employees[50];

    int employeesNum = 0;
    while (employeesNum < 50) {
        cout << "Enter name (enter 'fin' to terminate): ";
        cin >> employees[employeesNum].name;

        if (strcmp(employees[employeesNum].name, "fin") == 0) {
            cout << "Terminating data insertion." << endl;
            break;
        }

        cout<< "Enter tax number: ";
        cin >> employees[employeesNum].taxNum;

        cout << "Enter salary: ";
        cin >> employees[employeesNum].salary;

        cin.ignore();
        employeesNum++;
    }

    ofstream outputFile("test.bin", ios::binary);
    outputFile.write(reinterpret_cast<char*>(&employees), sizeof(employees)); // Write array to file
    outputFile.close();

    cout << "Data written to test.bin successfully." << endl;

    return 0;
}
