//
// Created by tonytech on 11.08.2025.
//

#include <iostream>
#include <sstream>
using namespace std;

struct KDA {
    unsigned int kills{0};
    unsigned int deaths{0};
    unsigned int assists{0};
};

struct Position {
    float x{0.0f};
    float y{0.0f};
};

struct Item {
    float speed{0.0f};
};

class Player {
    Position position;
    float speed;
    Item item1;
    KDA kda;

    [[nodiscard]] auto TransformKDAToString() const -> string {
        string result;
        result += to_string(this->kda.kills);
        result += " / ";
        result += to_string(this->kda.deaths);
        result += " / ";
        result += to_string(this->kda.assists);

        return result;
    }

    [[nodiscard]] auto GetSpeedSum() const -> float { return this->speed + this->item1.speed; }

public:
    // KDA &GetKDA() { return this->kda; }
    [[nodiscard]] auto GetKDA() const -> KDA { return this->kda; }

    // Class interfaces
    auto AddKill() -> void { ++this->kda.kills; }
    auto AddDeaths() -> void { ++this->kda.deaths; }
    auto AddAssists() -> void { ++this->kda.assists; }

    [[nodiscard]] auto GetKDAString() const -> string { return TransformKDAToString(); }

    auto Move() -> void {
        this->position.x += 1 * GetSpeedSum();
        this->position.y += 1 * GetSpeedSum();
    }

    [[nodiscard]] auto GetSpeed() const -> float { return this->speed; }
};


auto main() -> int {
    Player p;
    // p.kda.kills++;
    // p.kda.deaths++;

    cout << ">> Get kills thru getter method 'GetKDA()'" << endl;
    cout << p.GetKDA().kills << endl;

    cout << ">> Add kill for player via setter method 'AddKill()'" << endl;
    p.AddKill();

    cout << ">> Get deaths thru getter method 'GetKDA()' " << endl;
    cout << p.GetKDA().kills << endl;

    // Standard way -> the abstract way is to create method in class
    const KDA &kda = p.GetKDA();
    string result;
    result += to_string(kda.kills);
    result += " / ";
    result += to_string(kda.deaths);
    result += " / ";
    result += to_string(kda.assists);

    cout << ">> Print user stats" << endl;
    cout << result << endl;

    cout << ">> Get user stats thru getter method 'GetKDAString()'" << endl;
    cout << p.GetKDAString() << endl;

    cout << "Move player with method 'Move()'" << endl;
    p.Move();


    return 0;
}
