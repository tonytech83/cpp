//
// Created by tonytech on 11.08.2025.
//
#include <iostream>
#include <string>
using namespace std;

// non-encapsulated variable
const string PROJECT_NAME = "ProjectOne";

// encapsulated structure
struct PROJECT {
    const string NAME = "ProjectOne";
    const string VERSION = "1.0.0";
};

// Encapsulation group variables by specific sing
struct KDA {
    unsigned int kills{0};
    unsigned int deaths{0};
    unsigned int assists{0};
};

class Player {
public:
    KDA kda;
};


auto main() -> int {
    Player p;
    p.kda.kills++;
    p.kda.deaths++;

    // Print non-encapsulated variable
    cout << PROJECT_NAME << endl;

    return 0;
}
