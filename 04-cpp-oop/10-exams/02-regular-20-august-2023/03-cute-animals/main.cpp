//
// Created by tonytech on 04.10.2025.
//

#include <string>
using namespace std;

#include "Noises.h"

auto convertToUpper(string s) -> string {
    for (int i = 0; i < s.length(); i++)
        s[i] = toupper(s[i]);

    return s;
}

auto main() -> int {
    Noises noises;

    string time, noise;
    while (cin >> time >> noise) {

        if (convertToUpper(noise) == "THEEND")
            break;

        noises.registerNoise(time, noise);
    }

    cout << "----" << endl;
    noises.printStatistics(cout);

    return 0;
}
