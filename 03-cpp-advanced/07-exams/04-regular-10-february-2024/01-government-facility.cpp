//
// Created by tonytech on 12.7.2025.
//
#include <iostream>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

auto numberCheck(const string &line) -> bool {
    for (const char &c: line)
        if (isalpha(c))
            return false;

    return true;
}

auto printQueue(queue<string> q, const string &label) -> void {
    cout << label << ": ";
    if (q.empty()) {
        cout << "<empty>";
    } else {
        while (!q.empty()) {
            cout << q.front() << ' ';
            q.pop();
        }
    }
    cout << endl;
}

auto printStack(stack<string> s, const string &label) -> void {
    cout << label << ": ";
    if (s.empty()) {
        cout << "<empty>";
    } else {
        while (!s.empty()) {
            cout << s.top() << ' ';
            s.pop();
        }
    }
    cout << endl;
}

auto printStructures(const queue<string> &q1, const queue<string> &q2, const stack<string> &s) -> void {
    printQueue(q1, "1");
    printQueue(q2, "2");
    printStack(s, "3");
}

auto main() -> int {
    string line;

    queue<string> q1;
    queue<string> q2;
    stack<string> chairs;

    while (getline(cin, line) &&  line != "5") {
        string command = "0", name, queueNumber;
        if (numberCheck(line)) {
            command = line;
        } else {
            istringstream iss(line);
            iss >> name >> queueNumber;
        }

        if (command == "0") {
            if (queueNumber == "1")
                q1.push(name);
            else
                q2.push(name);
        } else if (command == "10" && !q1.empty())
            q1.pop();
        else if (command == "20" && !q2.empty())
            q2.pop();
        else if (command == "12" && !q1.empty()) {
            string temp = q1.front();
            q1.pop();
            q2.push(temp);
        } else if (command == "23" && !q2.empty()) {
            string temp = q2.front();
            q2.pop();
            chairs.push(temp);
        } else if (command == "31" && !chairs.empty()) {
            string temp = chairs.top();
            chairs.pop();
            q1.push(temp);
        } else if (command == "99") {
            printStructures(q1, q2, chairs);
        }
    }

    return 0;
}
