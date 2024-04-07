#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int choice, RandomNumber, guess;
    srand(time(0));

    cout << "Select the difficulty level:" << endl;
    cout << "1. Easy (1-8)" << endl;
    cout << "2. Medium (1-30)" << endl;
    cout << "3. Hard (1-50)" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            RandomNumber = rand() % 8 + 1;
            break;
        case 2:
            RandomNumber = rand() % 30 + 1;
            break;
        case 3:
            RandomNumber = rand() % 50 + 1;
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 0;
    }

    cout << "Guess the number: ";
    cin >> guess;

    if (guess == RandomNumber) {
        cout << "Congratulations! You guessed the correct number." << endl;
    } else {
        cout << "Sorry! The correct number was " << RandomNumber << "." << endl;
    }

    return 0;
}
