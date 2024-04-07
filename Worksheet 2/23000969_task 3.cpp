#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_BOOKS = 10;
const int MAX_TITLE_LENGTH = 150;

int main() {
    char titles[MAX_BOOKS][MAX_TITLE_LENGTH];
    char searchTitle[MAX_TITLE_LENGTH];

    cout << "Enter titles of 10 books:" << endl;
    for (int i = 0; i < MAX_BOOKS; ++i) {
        cout << "Book " << i + 1 << ": ";
        cin.getline(titles[i], MAX_TITLE_LENGTH);
    }

    ofstream outFile("books.dat", ios::binary);
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    outFile.write(reinterpret_cast<char*>(titles), sizeof(titles));
    outFile.close();

    cout << "\nEnter a title to search for: ";
    cin.getline(searchTitle, MAX_TITLE_LENGTH);

    ifstream inFile("books.dat", ios::binary);
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }

    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(titles), sizeof(titles))) {
        for (int i = 0; i < MAX_BOOKS; ++i) {
            if (strcmp(titles[i], searchTitle) == 0) {
                found = true;
                break;
            }
        }
    }

    inFile.close();

    if (found) {
        cout << "The title \"" << searchTitle << "\" is found in the file." << endl;
    } else {
        cout << "The title \"" << searchTitle << "\" is not found in the file." << endl;
    }

    return 0;
}
