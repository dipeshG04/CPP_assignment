#include <iostream>

using namespace std;

int main() {
    int numStudents;
    cout << "Enter the number of students in the class: ";
    cin >> numStudents;

    if (numStudents <= 0) {
        cout << "Invalid input. Number of students must be positive." << endl;
        return 1;
    }

    int attendance[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        attendance[i] = 0;
    }

    int presentCount = 0;

    while (true) {
        cout << "\nAttendance Menu:" << endl;
        cout << "1. Mark a student present" << endl;
        cout << "2. Mark a student absent" << endl;
        cout << "3. Display overall attendance percentage" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int studentId;
                cout << "Enter student ID (1-" << numStudents << "): ";
                cin >> studentId;

                if (studentId < 1 || studentId > numStudents) {
                    cout << "Invalid student ID. Please enter a number between 1 and " << numStudents << "." << endl;
                    break;
                }

                attendance[studentId - 1] = 1;
                presentCount++;
                cout << "Attendance marked for student " << studentId << ": Present" << endl;
                break;
            }
            case 2: {
                int studentId;
                cout << "Enter student ID (1-" << numStudents << "): ";
                cin >> studentId;

                if (studentId < 1 || studentId > numStudents) {
                    cout << "Invalid student ID. Please enter a number between 1 and " << numStudents << "." << endl;
                    break;
                }

                attendance[studentId - 1] = 0;
                presentCount--;
                cout << "Attendance marked for student " << studentId << ": Absent" << endl;
                break;
            }
            case 3: {
                float attendancePercentage = (static_cast<float>(presentCount) / numStudents) * 100;
                cout << "Overall attendance percentage: " << attendancePercentage << "%" << endl;
                break;
            }
            case 4: {
                cout << "Exiting program..." << endl;
                return 0;
            }
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
                break;
        }
    }

    return 0;
}
