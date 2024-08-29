#include <iostream>

using namespace std;

class Book {
private:
    char title[50];
    char author[50];
    int year;

public:
    void setTitle(char* t) {
        for (int i = 0; i < 50; i++) {
            title[i] = t[i];
        }
    }

    void setAuthor(char* a) {
        for (int i = 0; i < 50; i++) {
            author[i] = a[i];
        }
    }

    void setYear(int y) {
        year = y;
    }

    char* getTitle() {
        return title;
    }

    char* getAuthor() {
        return author;
    }

    int getYear() {
        return year;
    }
};

class Library {
private:
    Book* books;
    int size;
    int capacity;

public:
    Library(int c = 10) {
        capacity = c;
        size = 0;
        books = new Book[capacity];
    }

    ~Library() {
        delete[] books;
    }

    void addBook(Book b) {
        if (size < capacity) {
            books[size] = b;
            size++;
            cout << "Book added successfully!" << endl;
        } else {
            cout << "Library is full!" << endl;
        }
    }

    void displayBooks() {
        cout << "Book List:" << endl;
        cout << "Title                        Author           Year" << endl;
        for (int i = 0; i < size; i++) {
            cout << books[i].getTitle() << "          " << books[i].getAuthor() << "        " << books[i].getYear() << endl;
        }
    }

    void searchBook(char* title) {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (strcmp(books[i].getTitle(), title) == 0) {
                found = true;
                cout << "Book found!" << endl;
                cout << "Title: " << books[i].getTitle() << endl;
                cout << "Author: " << books[i].getAuthor() << endl;
                cout << "Year: " << books[i].getYear() << endl;
                break;
            }
        }
        if (!found) {
            cout << "Book not found!" << endl;
        }
    }
};

int main() {
    Library lib;
    int choice;
    char title[50], author[50];
    int year;

    while (true) {
        cout << "Menu" << endl;
        cout << "1 - Add Book" << endl;
        cout << "2 - Display Book" << endl;
        cout << "3 - Search Book" << endl;
        cout << "4 - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter title: ";
                cin.ignore();
                cin.getline(title, 50);
                cout << "Enter author: ";
                cin.getline(author, 50);
                cout << "Enter year: ";
                cin >> year;

                Book b;
                b.setTitle(title);
                b.setAuthor(author);
                b.setYear(year);

                lib.addBook(b);
                break;
            }
            case 2:
                lib.displayBooks();
                break;
            case 3: {
                cout << "Enter a book to search: ";
                cin.ignore();
                cin.getline(title, 50);
                lib.searchBook(title);
                break;
            }
            case 4:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}