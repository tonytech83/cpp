//
// Created by tonytech on 12/22/2024.
//

#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main() {
    int bad_scores_count;
    cin >> bad_scores_count;

    int total_tasks = 0, bad_tasks = 0, scores = 0;
    string previous_task_name;

    while (bad_scores_count > 0) {
        string task_name;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, task_name);


        if (task_name == "Enough") {
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << "Average score: " << scores * 1.0 / total_tasks << endl;
            cout << "Number of problems: " << total_tasks << endl;
            cout << "Last problem: " << previous_task_name << endl;
            return 0;
        }

        int task_score;
        cin >> task_score;

        total_tasks++;
        scores += task_score;
        previous_task_name = task_name;

        if (task_score <= 4) {
            bad_scores_count--;
            bad_tasks++;
        }
    }

    cout << "You need a break, " << bad_tasks << " poor grades." << endl;

    return 0;
}
