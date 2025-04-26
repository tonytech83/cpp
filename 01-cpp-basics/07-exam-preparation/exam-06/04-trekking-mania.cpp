//
// Created by TonyTech on 9.1.2025 г..
//

#include <iostream>
using namespace std;


int main() {
    int groups_count, musala = 0, montblanc = 0, kilimanjaro = 0, k2 = 0, everest = 0, total_people = 0;
    cin >> groups_count;

    for (int group = 1; group <= groups_count; group++) {
        int current_group_members;
        cin >> current_group_members;

        total_people += current_group_members;

        if (current_group_members <= 5) {
            musala += current_group_members;
        } else if (current_group_members >= 6 && current_group_members <= 12) {
            montblanc += current_group_members;
        } else if (current_group_members >= 13 && current_group_members <= 25) {
            kilimanjaro += current_group_members;
        } else if (current_group_members >= 26 && current_group_members <= 40) {
            k2 += current_group_members;
        } else {
            everest += current_group_members;
        }
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << musala * 100.0 / total_people << "%" << endl;
    cout << montblanc * 100.0 / total_people << "%" << endl;
    cout << kilimanjaro * 100.0 / total_people << "%" << endl;
    cout << k2 * 100.0 / total_people << "%" << endl;
    cout << everest * 100.0 / total_people << "%" << endl;

    return 0;
}
