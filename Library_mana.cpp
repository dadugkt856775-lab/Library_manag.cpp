
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;
    bool isIssued;

public:
    Book(int id, string t, string a) {
        bookID = id;
        title = t;
        author = a;
        isIssued = false;
    }

    int getID() {
        return bookID;
    }

    bool getStatus() {
        return isIssued;
    }

    void issueBook() {
        if (!isIssued) {
            isIssued = true;
            cout << "Book issued successfully!\n";
        } else {
            cout << "Book is already issued!\n";
        }
    }

    void returnBook() {
        if (isIssued) {
            isIssued = false;
            cout << "Book returned successfully!\n";
        } else {
            cout << "Book was not issued!\n";
        }
    }

    void display() {
        cout << "\nBook ID: " << bookID;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nStatus: "
             << (isIssued ? "Issued" : "Available");
        cout << "\n--------------------------\n";
    }
};

int main() {
    vector<Book> library;
    int choice, id;
    string title, author;
    bool found;

    do {
        cout << "\n===== LIBRARY MANAGEMENT =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter book ID: ";
            cin >> id;

            found = false;
            for (Book &b : library) {
                if (b.getID() == id) {
                    found = true;
                    break;
                }
            }

            if (found) {
                cout << "Book ID already exists!\n";
                break;
            }

            cout << "Enter book title: ";
            cin >> ws;
            getline(cin, title);

            cout << "Enter author name: ";
            getline(cin, author);

            library.emplace_back(id, title, author);
            cout << "Book added successfully!\n";
            break;

        case 2:
            if (library.empty()) {
                cout << "Library is empty!\n";
            } else {
                for (Book &b : library) {
                    b.display();
                }
            }
            break;

        case 3:
            cout << "Enter book ID to search: ";
            cin >> id;
            found = false;

            for (Book &b : library) {
                if (b.getID() == id) {
                    b.display();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Book not found!\n";
            break;

        case 4:
            cout << "Enter book ID to issue: ";
            cin >> id;
            found = false;

            for (Book &b : library) {
                if (b.getID() == id) {
                    b.issueBook();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Book not found!\n";
            break;

        case 5:
            cout << "Enter book ID to return: ";
            cin >> id;
            found = false;

            for (Book &b : library) {
                if (b.getID() == id) {
                    b.returnBook();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Book not found!\n";
            break;

        case 6:
            cout << "Exiting Library System...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
