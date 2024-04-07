#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string password;
    cout << "Enter a password: ";
    cin >> password;

    int length = password.length();
    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasDigit = false;
    bool hasSpecialChar = false;

    for (int i = 0; i < length; ++i) {
        char c = password[i];
        if (isupper(c)) {
            hasUpperCase = true;
        } else if (islower(c)) {
            hasLowerCase = true;
        } else if (isdigit(c)) {
            hasDigit = true;
        } else if (c >= 33 && c <= 47 || c >= 58 && c <= 64 || c >= 91 && c <= 96 || c >= 123 && c <= 126) {
            hasSpecialChar = true;
        }
    }

    int strengthPoints = 0;

    if (length >= 8) {
        strengthPoints += 5;
    }
    if (hasUpperCase && hasLowerCase) {
        strengthPoints += 3;
    }
    if (hasDigit) {
        strengthPoints += 1;
    }
    if (hasSpecialChar) {
        strengthPoints += 1;
    }

    string strength;
    if (strengthPoints >= 8) {
        strength = "Strong";
    } else if (strengthPoints >= 5) {
        strength = "Moderate";
    } else {
        strength = "Weak";
    }

    cout << "Password strength: " << strength << " (" << strengthPoints << " points)" << endl;

    return 0;
}
