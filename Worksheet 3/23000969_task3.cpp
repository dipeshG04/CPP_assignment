#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm> // Include <algorithm> for the unique function

using namespace std;

// Define a structure to hold patient information
struct Patient {
    string id;
    string treatment;
    string newPatient;
    int tokenNumber;
    time_t dateOfVisit;
};

// Define a class for the hospital department
class Department {
private:
    vector<Patient> patientQueue;

public:
    // Function to add a patient to the department's queue
    void addPatient(Patient patient) {
        patient.tokenNumber = patientQueue.size() + 1; // Assign a unique token number
        patientQueue.push_back(patient); // Add the patient to the queue
    }

    // Function to get the total number of patients in the department's queue
    int totalPatientsInQueue() {
        return patientQueue.size();
    }

    // Function to get the number of patients waiting in the department's queue
    int patientsWaiting() {
        return max(0, totalPatientsInQueue() - 1); // Subtract 1 to exclude the patient currently being served
    }

    // Function to display all patients in the department's queue
    void displayAllPatients() {
        cout << "All Patients in Queue:" << endl;
        for (const auto& patient : patientQueue) {
            cout << "Patient ID: " << patient.id << ", Treatment: " << patient.treatment << ", New Patient?: " << patient.newPatient << ", Token Number: " << patient.tokenNumber << ", Date of Visit: " << patient.dateOfVisit << endl;
        }
    }
};

// Function to display the department menu options
void displayDepartmentMenu() {
    cout << "Department Menu:" << endl;
    cout << "1. Add Patient" << endl;
    cout << "2. Show All Patients in Queue" << endl;
    cout << "3. Show Number of Patients Waiting" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Department pathology;
    Department gynecology;
    int choice;

    do {
        displayDepartmentMenu();
        cin >> choice;
        cin.ignore(); // Ignore newline character from input buffer

        switch (choice) {
            case 1: {
                int departmentChoice;
                cout << "Choose Department: " << endl;
                cout << "1. Pathology" << endl;
                cout << "2. Gynecology" << endl;
                cin >> departmentChoice;
                cin.ignore(); // Ignore newline character from input buffer

                Patient patient;
                cout << "Enter patient ID: ";
                getline(cin, patient.id);
                cout << "Enter treatment: ";
                getline(cin, patient.treatment);
                cout << "New patient? (Yes/No): ";
                getline(cin, patient.newPatient);
                cout << "Enter year of visit: ";
                cin >> patient.dateOfVisit;
                cout << "Enter month of visit: ";
                cin >> patient.dateOfVisit;
                cout << "Enter day of visit: ";
                cin >> patient.dateOfVisit;

                if (departmentChoice == 1) {
                    pathology.addPatient(patient);
                    cout << "Patient added to Pathology Department successfully." << endl;
                } else if (departmentChoice == 2) {
                    gynecology.addPatient(patient);
                    cout << "Patient added to Gynecology Department successfully." << endl;
                } else {
                    cout << "Invalid department choice." << endl;
                }
                break;
            }
            case 2: {
                int departmentChoice;
                cout << "Choose Department: " << endl;
                cout << "1. Pathology" << endl;
                cout << "2. Gynecology" << endl;
                cin >> departmentChoice;
                cin.ignore(); // Ignore newline character from input buffer

                if (departmentChoice == 1) {
                    pathology.displayAllPatients();
                } else if (departmentChoice == 2) {
                    gynecology.displayAllPatients();
                } else {
                    cout << "Invalid department choice." << endl;
                }
                break;
            }
            case 3: {
                int departmentChoice;
                cout << "Choose Department: " << endl;
                cout << "1. Pathology" << endl;
                cout << "2. Gynecology" << endl;
                cin >> departmentChoice;
                cin.ignore(); // Ignore newline character from input buffer

                if (departmentChoice == 1) {
                    cout << "Patients waiting in Pathology: " << pathology.patientsWaiting() << endl;
                } else if (departmentChoice == 2) {
                    cout << "Patients waiting in Gynecology: " << gynecology.patientsWaiting() << endl;
                } else {
                    cout << "Invalid department choice." << endl;
                }
                break;
            }
            case 4: {
                cout << "Exiting program..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please enter a valid option." << endl;
            }
        }
    } while (choice != 4);

    return 0;
}
