#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Define a Book structure
struct Book {
    string title;
    string author;
    float price;
    int quantity;
};

// Forward declarations
void addToCart(vector<Book>& cart, const Book& book);
void viewCart(const vector<Book>& cart);
void searchByTitle(vector<Book>& books, vector<Book>& cart, const string& query);
void searchByAuthor(vector<Book>& books, vector<Book>& cart, const string& query);
void checkout(vector<Book>& cart);

// Function to display the main menu
void displayMenu() {
    cout << "Welcome to the online bookstore, what would you like to do today? \n";
    cout << "1. Display Books\n";
    cout << "2. Search by Title\n";
    cout << "3. Search by Author\n";
    cout << "4. Add to Cart\n";
    cout << "5. View Cart\n";
    cout << "6. Checkout\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

// Function to display a list of books
void displayBooks(const vector<Book>& books) {
    cout << "Available Books:\n";
    for (const Book& book : books) {
        cout << "Title: " << book.title << " | Author: " << book.author << " | Price: Kshs. " << book.price << " | Quantity: " << book.quantity << endl;
    }
    cout << endl;
}

// Function to search for a book by title and add matching books to the cart
void searchByTitle(vector<Book>& books, vector<Book>& cart, const string& query) {
    string lowerCaseQuery = query;
    transform(lowerCaseQuery.begin(), lowerCaseQuery.end(), lowerCaseQuery.begin(), ::tolower);

    vector<Book> matchingBooks;

    for (Book& book : books) {
        string lowerCaseTitle = book.title;
        transform(lowerCaseTitle.begin(), lowerCaseTitle.end(), lowerCaseTitle.begin(), ::tolower);

        if (lowerCaseTitle.find(lowerCaseQuery) != string::npos) {
            matchingBooks.push_back(book);
        }
    }

    if (!matchingBooks.empty()) {
        cout << "Books Found:\n";
        for (const Book& match : matchingBooks) {
            cout << "Title: " << match.title << " | Author: " << match.author << " | Price: Kshs. " << match.price << " | Quantity: " << match.quantity << endl;
        }

        // Ask the user if they want to add books to the cart
        cout << "Do you want to add these books to the cart? (y/n): ";
        char addToCartChoice;
        cin >> addToCartChoice;

        // Declare the scope for adding books to the cart
        if (tolower(addToCartChoice) == 'y') {
            for (const Book& match : matchingBooks) {
                addToCart(cart, match);
            }
            cout << "Books added to cart.\n";
        } else {
            cout << "Books not added to cart.\n";
        }
    } else {
        cout << "No matching books found.\n";
    }
}

// Function to search for a book by author and add matching books to the cart
void searchByAuthor(vector<Book>& books, vector<Book>& cart, const string& query) {
    string lowerCaseQuery = query;
    transform(lowerCaseQuery.begin(), lowerCaseQuery.end(), lowerCaseQuery.begin(), ::tolower);

    vector<Book> matchingBooks;

    for (Book& book : books) {
        string lowerCaseAuthor = book.author;
        transform(lowerCaseAuthor.begin(), lowerCaseAuthor.end(), lowerCaseAuthor.begin(), ::tolower);

        if (lowerCaseAuthor.find(lowerCaseQuery) != string::npos) {
            matchingBooks.push_back(book);
        }
    }

    if (!matchingBooks.empty()) {
        cout << "Books Found:\n";
        for (const Book& match : matchingBooks) {
            cout << "Title: " << match.title << " | Author: " << match.author << " | Price: Kshs. " << match.price << " | Quantity: " << match.quantity << endl;
        }

        // Ask the user if they want to add books to the cart
        cout << "Do you want to add these books to the cart? (y/n): ";
        char addToCartChoice;
        cin >> addToCartChoice;

        // Declare the scope for adding books to the cart
        if (tolower(addToCartChoice) == 'y') {
            for (const Book& match : matchingBooks) {
                addToCart(cart, match);
            }
            cout << "Books added to cart.\n";
        } else {
            cout << "Books not added to cart.\n";
        }
    } else {
        cout << "No matching books found.\n";
    }
}

// Function to add a book to the shopping cart
void addToCart(vector<Book>& cart, const Book& book) {
    cart.push_back(book);
}

// Function to display the contents of the shopping cart
void viewCart(const vector<Book>& cart) {
    if (cart.empty()) {
        cout << "Your cart is empty.\n";
    } else {
        cout << "Shopping Cart:\n";
        for (const Book& book : cart) {
            cout << "Title: " << book.title << " | Author: " << book.author << " | Price: Kshs. " << book.price << endl;
        }
    }
}

// Function to perform checkout
void checkout(vector<Book>& cart) {
    if (cart.empty()) {
        cout << "Your cart is empty. Nothing to checkout.\n";
    } else {
        float totalAmount = 0;
        cout << "Checkout Summary:\n";
        for (const Book& book : cart) {
            cout << "Title: " << book.title << " | Price: Kshs. " << book.price << endl;
            totalAmount += book.price;
        }
        cout << "Total Amount: Kshs. " << totalAmount << endl;
        cout << "Thank you for shopping with us!\n";

        // Clear the cart after checkout
        cart.clear();
    }
}

int main() {
    // Sample books in the inventory
    vector<Book> books = {
        // ... (unchanged)
        {"Blossoms Of The Savannah", "Henry Ole Lulet", 1200, 14},
        {"A dolls house", "Henrik Ibsen", 700, 20},
        {"Hamlet", "William Shakespeare", 1500, 1},  // Added quantity for this book
        {"The Magic Tree House", "Mary Pope Osborne", 1500, 14},
        {"The Great Gatsby", "F. Scott Fitzgerald", 1500, 20},
        {"Relativity", "Albert Einstein", 3000, 3},
        {"Hackers Playbook", "Peter Kim", 6000, 2},
        {"To Kill a Mockingbird", "Harper Lee", 1500, 15},
        {"12 rules for life", "Jordan Peterson", 2000, 6},
        {"The Art of War", "Sun Tzu", 6000, 4},
        {"1984", "George Orwell", 700, 25},
        {"Hekaya za Abunwasi", "Baghdad", 300, 24},  // Added comma after the title
        {"Golden scales", "Anthony Horowitz", 1250, 12},
        {"StormBreaker", "Anthony Horowitz", 3000, 7},
        {"The River of Adventure", "Enid Blyton", 2500, 20},
        {"48 Laws of Power", "Robert Green", 2500, 12},
        {"The Wolf of Wallstreet", "Jordan Belfort", 6000, 3},
        {"Rich Dad, Poor Dad", "Robert Kiyosaki", 3000, 6},
        {"Grumpy Grinch", "Dr. Seuss", 500, 12},
        {"The Adventures of TinTin", "Herge", 1200, 17},
        
    };

    vector<Book> cart; // Shopping cart

    while (true) {
        displayMenu();

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                displayBooks(books);
                break;
            case 2: {
                cout << "Enter the title of the book to search: ";
                cin.ignore(); // Ignore newline from previous input
                string query;
                getline(cin, query);
                searchByTitle(books, cart, query);
                break;
            }
            case 3: {
                cout << "Enter the author's name to search: ";
                cin.ignore(); // Ignore newline from previous input
                string query;
                getline(cin, query);
                searchByAuthor(books, cart, query);
                break;
            }
            case 4: {
                cout << "Enter the title or author of the book to add to cart: ";
                cin.ignore();
                string query;
                getline(cin, query);
                searchByTitle(books, cart, query);
                searchByAuthor(books, cart, query);
                break;
            }

            case 5: {
                viewCart(cart);
                break;
            }
            case 6:
                checkout(cart);
                break;
            case 7:
                cout << "Exiting the program. Thank you!\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
