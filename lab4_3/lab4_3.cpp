#include <iostream>
#include <cstring>
using namespace std;

// Constants for maximum books and reviews
const int MAX_BOOKS = 100;  // Maximum number of books that the library can hold
const int MAX_REVIEWS = 100; // Maximum number of reviews per book

// Structure to hold a review's details
struct Review {
    char reviewer[50]; // Name of the reviewer
    char content[200]; // Content of the review
};

// Class to represent a book
class Book {
private:
    char title[100];           // Title of the book
    char author[100];          // Author of the book
    Review reviews[MAX_REVIEWS]; // Array to store reviews
    int reviewCount;           // Number of reviews for this book

public:
    // Constructor to initialize a book with a title and author
    Book(char* bookTitle, char* bookAuthor) {
        strcpy_s(title, sizeof(title), bookTitle); // Copy the title safely
        strcpy_s(author, sizeof(author), bookAuthor); // Copy the author safely
        reviewCount = 0; // Initialize review count to 0
        memset(reviews, 0, sizeof(reviews)); // Initialize the reviews array to zero
    }

    // Method to add a review to the book
    void addReview(char* reviewer, char* content) {
        if (reviewCount < MAX_REVIEWS) {
            // Copy the reviewer's name and content safely into the reviews array
            strcpy_s(reviews[reviewCount].reviewer, sizeof(reviews[reviewCount].reviewer), reviewer);
            strcpy_s(reviews[reviewCount].content, sizeof(reviews[reviewCount].content), content);
            reviewCount++; // Increment the review count
        }
        else {
            cout << "Cannot add more reviews; maximum reached.\n";
        }
    }

    // Method to search reviews for a specific text (in reviewer name or content)
    void searchReviews(char* query) {
        cout << "Search results for \"" << query << "\" in reviews of \"" << title << "\":\n";
        for (int i = 0; i < reviewCount; i++) {
            // Check if the query matches the reviewer's name or review content
            if (contains(reviews[i].reviewer, query) || contains(reviews[i].content, query)) {
                // If a match is found, print the reviewer and content
                cout << "Reviewer: " << reviews[i].reviewer << "\n";
                cout << "Content: " << reviews[i].content << "\n";
            }
        }
    }

    // Getter for the book's title
    char* getTitle() {
        return title;
    }

    // Getter for the book's author
    char* getAuthor() {
        return author;
    }

private:
    // Helper function to check if a substring exists in a string (case-insensitive)
    bool contains(char* str, char* substr) {
        return strstr(toLowerCase(str), toLowerCase(substr)) != nullptr;
    }

    // Helper function to convert a string to lowercase
    char* toLowerCase(char* str) {
        static char buffer[200];
        int i = 0;
        while (str[i] != '\0') {
            buffer[i] = tolower(str[i]); // Convert each character to lowercase
            i++;
        }
        buffer[i] = '\0'; // Null-terminate the string
        return buffer;
    }
};

// Class to represent a library containing multiple books
class Library {
private:
    Book* books[MAX_BOOKS]; // Array to store book objects
    int bookCount;          // Number of books in the library

public:
    // Constructor to initialize an empty library
    Library() {
        bookCount = 0; // Initialize book count to 0
        memset(books, 0, sizeof(books)); // Initialize books array to zero
    }

    // Destructor to free memory allocated for books
    ~Library() {
        for (int i = 0; i < bookCount; i++) {
            delete books[i]; // Free each dynamically allocated book
        }
    }

    // Method to add a book to the library
    void addBook(char* title, char* author) {
        if (bookCount < MAX_BOOKS) {
            books[bookCount] = new Book(title, author); // Dynamically allocate a new book
            bookCount++; // Increment the book count
        }
        else {
            cout << "Cannot add more books; maximum reached.\n";
        }
    }

    // Method to find a book in the library by title
    Book* findBook(char* title) {
        for (int i = 0; i < bookCount; i++) {
            // Compare titles (case-insensitive)
            if (strcmp(toLowerCase(books[i]->getTitle()), toLowerCase(title)) == 0) {
                return books[i]; // Return the book if found
            }
        }
        return nullptr; // Return nullptr if not found
    }

private:
    // Helper function to convert a string to lowercase
    char* toLowerCase(char* str) {
        static char buffer[100];
        int i = 0;
        while (str[i] != '\0') {
            buffer[i] = tolower(str[i]); // Convert each character to lowercase
            i++;
        }
        buffer[i] = '\0'; // Null-terminate the string
        return buffer;
    }
};

// Main function
int main() {
    Library library; // Create a library object

    // Add books to the library
    char book1Title[] = "1984";
    char book1Author[] = "George Orwell";
    library.addBook(book1Title, book1Author);

    char book2Title[] = "To Kill a Mockingbird";
    char book2Author[] = "Harper Lee";
    library.addBook(book2Title, book2Author);

    // Find a book and add reviews
    Book* book = library.findBook(book1Title);
    if (book) {
        char reviewer1[] = "Alice";
        char review1[] = "A haunting tale of dystopia.";
        book->addReview(reviewer1, review1); // Add first review

        char reviewer2[] = "Bob";
        char review2[] = "An eye-opening masterpiece.";
        book->addReview(reviewer2, review2); // Add second review
    }

    // Search reviews for specific text
    book = library.findBook(book1Title);
    if (book) {
        char query[] = "Alice";
        book->searchReviews(query); // Search reviews for "Alice"
    }

    return 0;
}
