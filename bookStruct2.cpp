#include <iostream>
using namespace std;

// Write a C++ program that defines a pointer to a Book struct. Dynamically allocate memory for the Book, assign values to its 
// fields using the pointer, and print the information. Make sure to deallocate the memory.

struct Book {
    string title;
    string author;
    int pages;
    int id;
};

void createBook(Book** library);
void outputBook(Book* myBook);
void outputLines(int num);
int outputMenu();
int getBookNum(int entries);

int main() {
    int librarySize = 0;
    Book** library = nullptr;
    int entries = 0;
    int option;
    int bookNum;

    // Prime Library - array of pointers to books
    while(librarySize <= 0) {
        cout << "Enter size of library: ";
        cin >> librarySize;
    }

    library = new Book*[librarySize];

    while (true) {
        option = outputMenu();

        switch (option) {
            case 1:
                if (entries < librarySize) {
                    createBook(library);
                    entries++;
                } else {
                    cout << "Library is full." << endl;
                }
                break;

            case 2:
                bookNum = getBookNum(entries);
                if (bookNum != -1) {
                    outputBook(library[bookNum]);
                }
                break;

            default:
                return 0; 
        }
    }
}

void createBook(Book** library) {
    Book* myBook = new Book;
    static int bookCount = 1;

    cin.ignore();
    cout << "Enter Title: ";
    getline(cin, myBook->title);
    cout << "Enter Author: ";
    getline(cin, myBook->author);
    cout << "Enter Page Number: ";
    cin >> myBook->pages;

    myBook->id = bookCount++;

    library[bookCount - 1] = myBook;
}

void outputBook(Book* myBook) {
    cout << "\nYour Book" << endl;
    outputLines(40);
    cout << "Title : " << myBook->title << endl;
    cout << "Author : " << myBook->author << endl;
    cout << "Page Num : " << myBook->pages << endl;
    cout << "Id : " << myBook->id << endl;
    outputLines(40);
}

void outputLines(int num) {
    for (int x = 0; x < num; x++) {
        cout << "-";
    }
    cout << endl;
}

int outputMenu() {
    int option = 0;

    cout << "\nMenu: " << endl;
    outputLines(40);
    cout << "Option 1 - Enter a Book" << endl;
    cout << "Option 2 - Show a Book" << endl;
    cout << "Option 3 - Exit" << endl;
    outputLines(40);

    while (option != 1 && option != 2 && option != 3) {
        cout << "Enter choice: ";
        cin >> option;
    }
    return option;
}

int getBookNum(int entries) {
    int bookNum;
    do {
        if (entries == 0) {
            cout << "No Books Entered!" << endl;
            return -1;
        }
        cout << "Enter book number: ";
        cin >> bookNum;
    } while (bookNum > entries || bookNum <= 0);
    return bookNum;
}