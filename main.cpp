#include <iostream>
#include <vector>
#include <limits>
#include "models/Book.h"
#include "models/User.h"
#include "utils/LibraryUtils.h"
using namespace std;

// --- Forward Declarations for Menu Functions ---
void runAdminSession();
void runUserSession();

// STUDENT TASK: Implement a function that uses a fixed-size array.
// This exercise covers: arrays
void showPromotionalBooks() {
    // 1. Declare a fixed-size array of type 'int' named 'promoIDs'.
    // 2. Initialize it with three hard-coded book IDs, for example: {1, 5, 10}.
    // 3. Print a header, like "--- Today's Featured Books (IDs) ---".
    // 4. Write a loop to iterate through the 'promoIDs' array and print each ID.
}

// --- MAIN APPLICATION (FRAMEWORK) ---

int main() {
    // This part handles login and routing to the correct session.
    // It is provided as a framework for your functions.
    vector<User> users = loadUsers();
    while (true) {
        // ... Login menu and logic ...
        // [The full menu logic from the previous complete answer would go here]
        Role userRole = loginUser(users); // Example call
        if (userRole == Role::ADMIN) {
            runAdminSession();
        } else if (userRole == Role::USER) {
            runUserSession();
        }
    }
    return 0;
}

void runAdminSession() {
    // The main loop for the admin is provided.
    // It calls the functions you will implement in LibraryUtils.cpp.
    vector<Book> libraryBooks = loadBooks();
    bool booksAreSorted = false;
    
    while(true) {
        // ... Admin menu and switch statement ...
        // Example case:
        // case 1: addBook(libraryBooks); booksAreSorted = false; break;
        // case 7: showPromotionalBooks(); break; // <-- Your new array function
       cout << "\n ---- Admin Menu ----\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. View All Books\n";
        cout << "4. Search Book by ID\n";
        cout << "5. Sort Books by Title\n";
        cout << "6. Sort Books by Author\n";
        cout << "7. Show Promotional Books\n";
        cout << "0. Logout\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(libraryBooks);
                booksAreSorted = false;
                break;
            case 2:
                removeBook(libraryBooks);
                break;
            case 3:
                viewAllBooks(libraryBooks);
                break;
            case 4:
                searchBookById(libraryBooks);
                break;
            case 5:
                sortBooksByTitle(libraryBooks);
                break;
            case 6:
                sortBooksByAuthor(libraryBooks);
                break;
            case 7:
                showPromotionalBooks();
                break;
            case 0:
                cout << "Logging out from this session...\n";
                return;
            default:
                cout << "Invalid choice.\n";
        }
    }
}

// --- USER SESSION ---
void runUserSession() {
    while (true) {
        cout << "\n===== User Menu =====\n";
        cout << "1. View All Books\n";
        cout << "2. Search Book by ID\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Show Promotional Books\n";
        cout << "0. Logout\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n--- All Books ---\n";
                showAllBooks();
                break;
            case 2: {
                cout << "\nEnter Book ID: ";
                int id;
                cin >> id;
                searchBookById(id);
                break;
            }
            case 3: {
                cout << "\nEnter Book ID to Borrow: ";
                int id;
                cin >> id;
                borrowBook(id);
                break;
            }
            case 4: {
                cout << "\nEnter Book ID to Return: ";
                int id;
                cin >> id;
                returnBook(id);
                break;
            }
            case 5:
                showPromotionalBooks();
                break;
            case 0:
                cout << "Logging out...\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}