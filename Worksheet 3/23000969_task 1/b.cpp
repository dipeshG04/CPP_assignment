#include <iostream>
#include <stack>
#include<string>
using namespace std;

string decimalToBinary(int decimal) {
    if (decimal == 0)  // Handling the special case when decimal is 0
        return "0";

    stack<int> binaryStack;

    while (decimal > 0) {
        binaryStack.push(decimal % 2);
        decimal /= 2;
    }

    string binaryString;
    while (!binaryStack.empty()) {
        binaryString += to_string(binaryStack.top());
        binaryStack.pop();
    }

    return binaryString;
}

int main() {
    int decimal;
    cout << "Enter a decimal number: ";
    cin >> decimal;

    string binary = decimalToBinary(decimal);
    cout << "Binary representation: " << binary << endl;

    return 0;
}
