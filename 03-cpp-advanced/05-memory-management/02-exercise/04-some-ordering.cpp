//
// Created by tonytech on 08.07.2025.
//
#include <iostream>
#include <memory>
using namespace std;

constexpr int MAX_LINE_SIZE = 200;

auto readLine(istream &in, char *buffer) -> size_t {
    size_t lineSize = 0;

    char ch;
    while (in.get(ch) && ch != '\n') {
        buffer[lineSize++] = ch;

        if (lineSize >= MAX_LINE_SIZE) {
            cout << "Too many characters! Max characters: 200" << endl;
            // terminate the program immediately
            exit(-1);
        }
    }

    buffer[lineSize] = '\0';
    return lineSize;
}

auto processLine(const char *line, int (*processor)(int), const int lineSize) -> unique_ptr<char[]> {
    unique_ptr<char[]> buffer(new char[lineSize]);

    for (int i = 0; i < lineSize; i++)
        buffer[i] = static_cast<char>(processor(line[i]));

    return buffer;
}


auto main() -> int {

    char *line = new char[MAX_LINE_SIZE];
    const size_t lineSize = readLine(cin, line);

    const unique_ptr<char[]> toLowerCase = processLine(line, ::tolower, static_cast<int>(lineSize));
    const unique_ptr<char[]> toUpperCase = processLine(line, ::toupper, static_cast<int>(lineSize));

    cout << toLowerCase.get() << endl;
    cout << toUpperCase.get() << endl;

    delete[] line;

    return 0;
}
