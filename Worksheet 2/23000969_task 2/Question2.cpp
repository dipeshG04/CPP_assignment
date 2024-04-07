#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    int product_code;

public:
    Product(int code) : product_code(code) {}

    virtual void show() {
        cout << "Product Code: " << product_code << endl;
    }
};

class Book : public Product {
private:
    string book_title;

public:
    Book(int code, const string& title) : Product(code), book_title(title) {}

    void show() override {
        Product::show();
        cout << "Book Title: " << book_title << endl;
    }
};

void display(Product* ptr1, Product* ptr2) {
    ptr1->show();
    ptr2->show();
}

int main() {
    int code;
    string title;

    cout << "Enter product code: ";
    cin >> code;

    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, title);

    Product product(code);
    product.show();

    Book book(code + 100, title);
    book.show();

    cout << "\nCreating another book...\n";
    cout << "Enter product code: ";
    cin >> code;

    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, title);

    Book anotherBook(code, title);
    display(&book, &anotherBook);

    return 0;
}

