
#include <iostream>
#include <string>
#include <limits>

#include "CircularLinkedList.h"
#include "CreateBook.h"

#include "Insert.h"
#include "Remove.h"
#include "InsertAt.h"
#include "RemoveAt.h"
#include "Swap.h"
#include "Sort.h"
#include "Reverse.h"
#include "Print.h"
#include "MoveToNextBook.h"
#include "CheckStatus.h"

using namespace std;

int main() {
    CircularLinkedList library;
    int choice;

    do {
        cout << "\n========================================\n";
        cout << " CIRCULAR LIBRARY BOOK DISPLAY SYSTEM\n";
        cout << "========================================\n";
        cout << "1. Display All Books\n";
        cout << "2. Insert Book at Head\n";
        cout << "3. Remove Book from Head\n";
        cout << "4. Insert Book at Index\n";
        cout << "5. Remove Book at Index\n";
        cout << "6. Swap Books\n";
        cout << "7. Sort Books by ID\n";
        cout << "8. Reverse Book Collection\n";
        cout << "9. Move to Next Book\n";
        cout << "10. Check Collection Status\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number.\n";
            continue;
        }

        int id, index, index1, index2;
        string title;
        BookNode* removed;

        switch (choice) {
        case 1:
            PrintBooks(library);
            break;

        case 2:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Book Title: ";
            getline(cin, title);

            InsertBook(library, CreateBook(id, title));
            cout << "Book inserted successfully.\n";
            break;

        case 3:
            removed = RemoveBook(library);

            if (removed != nullptr) {
                cout << "Removed: " << removed->title << '\n';
                delete removed;
            } else {
                cout << "Collection is empty.\n";
            }
            break;

        case 4:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Book Title: ";
            getline(cin, title);

            cout << "Enter index: ";
            cin >> index;

            InsertBookAt(library, CreateBook(id, title), index);
            cout << "Book inserted successfully.\n";
            break;

        case 5:
            cout << "Enter index to remove: ";
            cin >> index;

            removed = RemoveBookAt(library, index);

            if (removed != nullptr) {
                cout << "Removed: " << removed->title << '\n';
                delete removed;
            } else {
                cout << "Collection is empty.\n";
            }
            break;

        case 6:
            cout << "Enter first index: ";
            cin >> index1;
            cout << "Enter second index: ";
            cin >> index2;

            SwapBooks(library, index1, index2);
            cout << "Swap operation completed.\n";
            break;

        case 7:
            SortBooks(library);
            cout << "Books sorted by ID.\n";
            break;

        case 8:
            ReverseBooks(library);
            cout << "Collection reversed.\n";
            break;

        case 9:
            MoveToNextBook(library);
            break;

        case 10:
            CheckCollectionStatus(library);
            break;

        case 11:
            cout << "Program closed.\n";
            break;

        default:
            cout << "Invalid choice. Select 1 to 11.\n";
        }

    } while (choice != 11);

    return 0;
}
