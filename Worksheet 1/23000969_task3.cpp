#include <iostream>
#include <string>

using namespace std;

struct Item {
    int productId;
    string name;
    int quantity;
    double price;
};

void addItem(Item inventory[], int& itemCount, const int MAX_INVENTORY_SIZE);
void removeItem(Item inventory[], int& itemCount);
void updateItem(Item inventory[], int itemCount);
void displayInventory(const Item inventory[], int itemCount);

int main() {
    const int MAX_INVENTORY_SIZE = 100;
    Item inventory[MAX_INVENTORY_SIZE];
    int itemCount = 0;
    char choice;

    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Update Item\n";
        cout << "4. Display Inventory\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1':
                addItem(inventory, itemCount, MAX_INVENTORY_SIZE);
                break;
            case '2':
                removeItem(inventory, itemCount);
                break;
            case '3':
                updateItem(inventory, itemCount);
                break;
            case '4':
                displayInventory(inventory, itemCount);
                break;
            case '5':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '5');

    return 0;
}

void addItem(Item inventory[], int& itemCount, const int MAX_INVENTORY_SIZE) {
    if (itemCount >= MAX_INVENTORY_SIZE) {
        cout << "Inventory is full. Cannot add more items.\n";
        return;
    }

    cout << "Enter product ID: ";
    cin >> inventory[itemCount].productId;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, inventory[itemCount].name);
    cout << "Enter quantity: ";
    cin >> inventory[itemCount].quantity;
    cout << "Enter price: ";
    cin >> inventory[itemCount].price;

    itemCount++;
    cout << "Item added to inventory.\n";
}

void removeItem(Item inventory[], int& itemCount) {
    if (itemCount == 0) {
        cout << "Inventory is empty. Cannot remove items.\n";
        return;
    }

    int productId;
    cout << "Enter product ID to remove: ";
    cin >> productId;

    for (int i = 0; i < itemCount; ++i) {
        if (inventory[i].productId == productId) {
            for (int j = i; j < itemCount - 1; ++j) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            cout << "Item removed from inventory.\n";
            return;
        }
    }
    cout << "Item with ID " << productId << " not found in inventory.\n";
}

void updateItem(Item inventory[], int itemCount) {
    if (itemCount == 0) {
        cout << "Inventory is empty. Cannot update items.\n";
        return;
    }

    int productId;
    cout << "Enter product ID to update: ";
    cin >> productId;

    for (int i = 0; i < itemCount; ++i) {
        if (inventory[i].productId == productId) {
            cout << "Enter new quantity: ";
            cin >> inventory[i].quantity;
            cout << "Enter new price: ";
            cin >> inventory[i].price;
            cout << "Item updated in inventory.\n";
            return;
        }
    }
    cout << "Item with ID " << productId << " not found in inventory.\n";
}

void displayInventory(const Item inventory[], int itemCount) {
    if (itemCount == 0) {
        cout << "Inventory is empty.\n";
    } else {
        cout << "Inventory:\n";
        for (int i = 0; i < itemCount; ++i) {
            cout << "Product ID: " << inventory[i].productId << ", Name: " << inventory[i].name << ", Quantity: " << inventory[i].quantity << ", Price: " << inventory[i].price << endl;
        }
    }
}
