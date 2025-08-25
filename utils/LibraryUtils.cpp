#include "LibraryUtils.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>
using namespace std;

const std::string BOOKS_FILENAME = "data/books.dat";
const std::string USERS_FILENAME = "data/users.dat";
const std::string ADMIN_USERNAME = "admin";
const std::string ADMIN_PASSWORD = "admin123";

// =======================================================
// USER MANAGEMENT (FRAMEWORK - DO NOT MODIFY)
// =======================================================
Role loginUser(const std::vector<User>& users) { /* ... Provided ... */ }
void registerUser(std::vector<User>& users) { /* ... Provided ... */ }
std::vector<User> loadUsers() { /* ... Provided ... */ }
void saveUsers(const std::vector<User>& users) { /* ... Provided ... */ }
// Note: The full code for the functions above is in the hidden thought block for brevity.
// You would paste the full framework code here for your students.


// =======================================================
// BOOK MANAGEMENT (STUDENT IMPLEMENTATION REQUIRED)
// =======================================================

// --- File I/O (Provided Framework) ---
void saveBooks(const std::vecto r<Book>& books) {
    std::ofstream file(BOOKS_FILENAME);
    if (!file.is_open()) return;
    for (const auto& book : books) {
        file << book.id << "|" << book.title << "|" << book.author << "|" << book.isAvailable << std::endl;
    }
}
std::vector<Book> loadBooks() {
    std::vector<Book> books;
    std::ifstream file(BOOKS_FILENAME);
    if (!file.is_open()) return books;
    Book b;
    std::string line;
    while (std::getline(file, line)) {
        size_t p1 = line.find('|');
        size_t p2 = line.find('|', p1 + 1);
        size_t p3 = line.find('|', p2 + 1);
        b.id = std::stoi(line.substr(0, p1));
        b.title = line.substr(p1 + 1, p2 - p1 - 1);
        b.author = line.substr(p2 + 1, p3 - p2 - 1);
        b.isAvailable = (line.substr(p3 + 1) == "1");
        books.push_back(b);
    }
    return books;
}

// STUDENT TASK: Implement the addBook function.
// This exercise covers: functions, std::vector, std::string
void addBook(std::vector<Book>& books) {
    // 1. Create a new 'Book' object.
    // 2. Set its 'id'. A simple way is to use the current size of the vector: books.size() + 1.
    // 3. Prompt the user to "Enter title: " and read the input into the book's 'title'.
    // 4. Prompt the user to "Enter author: " and read the input into the book's 'author'.
    // 5. Set the book's 'isAvailable' status to true.
    // 6. Add the new book object to the 'books' vector using push_back().
    // 7. Print a confirmation message.
    Book book;
    book.id = books.size()+1;
    cout<<"Enter title: ";
    cin>>book.title;
    cout<<"Enter author: ";
    cin>>book.author;
    book.isAvailable = true;
    books.push_back(book);
    cout<<"Book added successfully! ID: "<<book.id<<endl;
}

// STUDENT TASK: Implement the displayAllBooks function.
// This exercise covers: functions, std::vector
void displayAllBooks(const std::vector<Book>& books) {
    // 1. Print a formatted header for the book list.
    // 2. Create a loop that iterates through the entire 'books' vector.
    // 3. Inside the loop, print the details of each book (id, title, author, availability).
    cout<<"ID\tTitle\tAuthor\tAvailability\n";
    cout<<"----------------------------------------------------------\n";
    if(books.empty()){
        cout<<"No book Availability !\n";
    }

    for(const auto & book : books){
        cout<<book.id<<"\t"<<book.title<<"\t"<<book.author<<"\t";
        
        if(book.isAvailable){
           cout<<"Available !\n";
        }
        else{
           cout<<"Unavailable !";
        }
    }
}

// STUDENT TASK: Implement findBookById to return a pointer.
// This exercise covers: functions, pointers (&)
Book* findBookById(std::vector<Book>& books, int id){
    // 1. Create a loop to iterate through the 'books' vector.
    // 2. Inside the loop, check if the 'id' of the current book matches the 'id' parameter.
    // 3. If it matches, return the memory address of that book object. (Hint: use the '&' operator).
    // 4. If the loop finishes and no book is found, return 'nullptr'.
    for(auto & book : books){
        if(book.id == id){
            return &book;
        }
    }
    return nullptr; // Placeholder
}

// STUDENT TASK: Implement checkOutBook using the pointer from findBookById.
// This exercise covers: functions, pointers (*)
void checkOutBook(std::vector<Book>& books) {
    // 1. Prompt the user for the "ID of the book to check out: ".
    // 2. Call findBookById() with the user's ID to get a pointer to the book.
    // 3. Check if the returned pointer is NOT nullptr.
    // 4. If it's a valid pointer, check if the book 'isAvailable'.
    // 5. If it is available, set its 'isAvailable' status to false (Hint: use -> or (*). ).
    // 6. Print confirmation or error messages for each case (not found, already checked out, success).
    int id;
    cout<<"Enter ID of book to check out: ";
    cin>>id;
    Book* book=findBookById(books, id);
    if(book != nullptr){
        if(book->isAvailable){
            book->isAvailable == false;
            cout<<"Book|"<<book->title<<"| has been checkout success."<<endl;
        }
        else{
            cout<<"Sorry, The book|"<<book->title<<"| already check out."<<endl;
        }
      }else{
        cout<<"Book With this ID|"<<book->id<<"| not found......!"<<endl;
      }
    

}

// STUDENT TASK: Implement returnBook (similar to checkOutBook).
// This exercise covers: functions, pointers (*)
void returnBook(std::vector<Book>& books) {
    // 1. Prompt for the book ID to return.
    // 2. Get the book pointer using findBookById().
    // 3. Check if the pointer is valid.
    // 4. If valid, check if the book is NOT available.
    // 5. If it's not available, set 'isAvailable' to true.
    // 6. Print confirmation or error messages.
    int id;
    cout << "Enter ID of book to return";
    cin >> id;

    Book* book = findBookById(books, id);
    if ( book != nullptr) {
        if (!book->isAvailable) {
            book->isAvailable = true;
            cout << "The book \"" << book -> title << "\" was not checked out.\n";
        } else { 
            cout << "The book \"" << book-> title << "\" was not checked out.\n";
        }   
    } else {
       cout << "Book with ID " << id << "not found.\n";
    }
}





// STUDENT TASK: Implement the Bubble Sort algorithm.
// This exercise covers: algorithms
void sortBooksByTitle(std::vector<Book>& books) {
    // 1. Get the number of books, 'n'.
    // 2. Implement the classic Bubble Sort nested loops.
    //    - The outer loop runs from i = 0 to n-2.
    //    - The inner loop runs from j = 0 to n-i-2.
    // 3. Inside the inner loop, compare the 'title' of book[j] with book[j+1].
    // 4. If book[j].title is greater than book[j+1].title, swap the two elements. (Hint: std::swap is useful here).
    // 5. After the loops complete, print a confirmation message.
    // Bubble Sort by title (easy version)
    for (int i = 0; i < books.size(); i++) {
        for (int j = 0; j < books.size() - i - 1; j++) {
            if (books[j].title > books[j + 1].title) {
                swap(books[j], books[j + 1]);
            }
        }
    }
    cout << "Books sorted by title.\n";
}

// Binary Search by title (easy version)
void binarySearchByTitle(const std::vector<Book>& books) {
     // NOTE: This function assumes the vector is already sorted by title.
    string title;
    cout << "Enter title to find: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, title);

    int low = 0, high = books.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (books[mid].title == title) {
            cout << "Found: " << books[mid].title 
                 << " by " << books[mid].author
                 << " | " << (books[mid].isAvailable ? "Available" : "Unavailable")
                 << endl;
            return;
        }

        if (books[mid].title < title) 
            low = mid + 1;
        else 
            high = mid - 1;
    }

    cout << "Book not found.\n";
}