#include <iostream>
using namespace std;

struct Book {
    string title;
    string author;
    int pages;
};

void outputBook(Book myBook);
void outputLine(int size);

int main() {
    Book myBook;

    cout << "Enter book title: ";
    getline(cin, myBook.title);

    cout << "Enter book author: ";
    cin >> myBook.author;

    cout << "Enter book pages: ";
    cin >> myBook.pages;

    outputBook(myBook);

    return 0;
}

void outputBook(Book myBook) {
    cout << "\nYOUR BOOK:" << endl;
    outputLine(40);

    cout << "Title: " << myBook.title << endl;
    cout << "Author: " << myBook.author << endl;
    cout << "Page Num: " << myBook.pages << endl;

    outputLine(40);
}

void outputLine(int size) {
    for (int x = 0; x < size; x++) {
        cout << "-";
    }
    cout << endl;
}