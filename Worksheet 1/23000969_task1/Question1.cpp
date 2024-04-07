#include <iostream>
using namespace std;

int main() {
    float temperature;
    char scale;

    cout << "Enter temperature: ";
    cin >> temperature;
    cout << "Choose scale (C/F): ";
    cin >> scale;

    if (scale == 'C') {
        float fahrenheit = (temperature * 9 / 5) + 32;
        cout << "Temperature in Fahrenheit: " << fahrenheit << endl;
    } else if (scale == 'F') {
        float celsius = (temperature - 32) * 5 / 9;
        cout << "Temperature in Celsius: " << celsius << endl;
    } else {
        cout << "Invalid scale! Please enter 'C' or 'F'." << endl;
    }

    return 0;
}

