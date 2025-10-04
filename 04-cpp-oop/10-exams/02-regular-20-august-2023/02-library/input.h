#pragma once
#include <iostream>
#include <map>
#include <string>
using namespace std;


template<typename T>
void read(map<size_t, T> &books, istream &in) {
    while (true) {
        string line;
        if (!getline(in, line))
            break;
        if (line == "end")
            break;
        if (line.empty())
            continue;

        size_t id = static_cast<size_t>(stoull(line));
        T book(id, in);
        books[id] = book;
    }
}

// prepare template declaration for both print functions in main.cpp
template<typename T>
void print(const T &x, ostream &out);

// definition for a single Book-like object
template<typename T>
void print(const T &book, ostream &out) {
    out << "book " << book.getId() << " \"" << book.getTitle() << "\"" << " by \"" << book.getAuthor() << "\" is ";
    if (book.getBorrower().empty())
        out << "\"available\"";
    else
        out << "\"borrowed by " << book.getBorrower() << "\"";
    out << endl;
}

// specialization for map<size_t, Book>* (matches main.cpp)
template<>
inline void print<map<size_t, class Book> *>(map<size_t, class Book> *const &booksPtr, ostream &out) {
    auto &books = *booksPtr;
    out << "-----\n";
    out << "total books: " << books.size() << '\n';
    for (const auto &kv: books)
        print(kv.second, out);
}

template<typename T>
void borrow(T &book, const string &borrower) {
    book.setBorrowed(borrower);
    print(book, cout);
}
template<typename T>
void borrow(T &book) {
    book.setBorrowed("");
    print(book, cout);
}
