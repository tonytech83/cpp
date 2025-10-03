//
// Created by tonytech on 3.10.2025.
//

#ifndef CPP_INPUT_H
#define CPP_INPUT_H

#include <string>

template<class T>
auto read(map<size_t, T> &books, istream &in) -> void {
    std::string token;
    while (in >> token && token != "end") {
        int id;

        std::istringstream istr(token);
        istr >> id;

        books[id] = T(id, istr);
    }
}

// For printing all books - declare first
template<class U>
auto print(std::map<size_t, U> *const &books, std::ostream &out) -> void {
    for (const auto &pair : *books) {
        out << "book " << pair.second.getId() << " " << pair.second.getTitle() << " by "
            << pair.second.getAuthor() << " is " << pair.second.getBorrower() << std::endl;
    }
}

// For printing a single book
template<class T>
auto print(const T &item, std::ostream &out) -> void {
    out << "book " << item.getId() << " " << item.getTitle() << " by "
        << item.getAuthor() << " is " << item.getBorrower() << std::endl;
}

template<class T>
auto borrow(T &book) -> void {}

template<class T>
auto borrow(T &book, const string &borrower) -> void {}

#endif // CPP_INPUT_H
