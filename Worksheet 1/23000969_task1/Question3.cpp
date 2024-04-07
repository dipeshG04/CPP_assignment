#include<iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of integers: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minimum = arr[0];
    int maximum = arr[0];

    for (int i = 1; i < n; ++i) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }

    cout << "Minimum value: " << minimum << endl;
    cout << "Maximum value: " << maximum << endl;

    return 0;
}
