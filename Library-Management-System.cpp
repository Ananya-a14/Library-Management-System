#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isIssued;
};

vector<Book> library;

void addBook(int id, string title, string author) {
    library.push_back({id, title, author, false});
    cout << "Book added successfully!\n";
}

void displayBooks() {
    cout << "\nAvailable Books:\n";
    for (const auto& book : library) {
        if (!book.isIssued) {
            cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << endl;
        }
    }
}

void issueBook(int id) {
    for (auto& book : library) {
        if (book.id == id && !book.isIssued) {
            book.isIssued = true;
            cout << "Book issued successfully!\n";
            return;
        }
    }
    cout << "Book not available or already issued.\n";
}

void returnBook(int id) {
    for (auto& book : library) {
        if (book.id == id && book.isIssued) {
            book.isIssued = false;
            cout << "Book returned successfully!\n";
            return;
        }
    }
    cout << "Invalid book ID or book not issued.\n";
}

int main() {
    int choice, id;
    string title, author;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n2. Display Books\n3. Issue Book\n4. Return Book\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore(); // Clear input buffer
                cout << "Enter Book Title: ";
                getline(cin, title);
                cout << "Enter Author Name: ";
                getline(cin, author);
                addBook(id, title, author);
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                cout << "Enter Book ID to issue: ";
                cin >> id;
                issueBook(id);
                break;
            case 4:
                cout << "Enter Book ID to return: ";
                cin >> id;
                returnBook(id);
                break;
            case 5:
                cout << "Exiting system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
