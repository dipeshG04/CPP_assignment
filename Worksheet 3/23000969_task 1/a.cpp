#include <iostream>
#include <list>
#include <algorithm> // Include for reverse
using namespace std;

int main() {
    list<int> myList = {1, 2, 3, 4, 5};

    cout << "Original list: ";
    for (const auto& num : myList) {
        cout << num << " ";
    }
    cout << endl;

    myList.reverse(); // Using list's member function reverse()

    cout << "Reversed list: ";
    for (const auto& num : myList) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
