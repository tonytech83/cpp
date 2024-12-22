//
// Created by tonytech on 12/22/2024.
//

#include <iostream>
#include <string>

using namespace std;

string output(const bool found, const int books_count) {
    if (found) {
        return "You checked " + to_string(books_count) + " books and found it.";
    }
    return "The book you search is not here!\nYou checked " + to_string(books_count) + " books.\n";
}

int main(){
    string wanted_book,book;
    getline(cin, wanted_book);
    getline(cin, book);

    int books_count = 0;
    bool found = false;

    while (book != "No More Books") {
        if (wanted_book == book) {
            found = true;
            break;
        }

        books_count++;
        getline(cin, book);
    }

    cout << output(found, books_count) << endl;

    return 0;
}

