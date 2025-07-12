#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

auto findNumberFrequency(const vector<int> &message, const unordered_set<int> &separators,
                         unordered_map<int, int> &freq) -> void {
    unordered_set<int> part;

    for (int num: message) {
        // if the current number from the message is separator,
        // we put create key and increment the value into freq map
        if (separators.count(num)) {
            for (int value: part)
                freq[value]++;
            // clear the current part after it end
            part.clear();
        } else {
            part.insert(num);
        }
    }

    // check the last part for left numbers
    for (int value: part)
        freq[value]++;
}

auto main() -> int {
    unordered_set<int> separators;
    string line;
    getline(cin, line);
    istringstream iss(line);
    int separator;
    while (iss >> separator)
        separators.insert(separator);

    vector<int> message;
    getline(cin, line);
    istringstream msgStream(line);
    int number;
    while (msgStream >> number)
        message.push_back(number);

    unordered_map<int, int> freq;
    findNumberFrequency(message, separators, freq);

    int searchValue;
    while (cin >> searchValue && searchValue != 0)
        cout << freq[searchValue] << '\n';

    return 0;
}
