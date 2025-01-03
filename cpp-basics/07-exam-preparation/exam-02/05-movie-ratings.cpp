//
// Created by TonyTech on 3.1.2025 г..
//

#include <cfloat>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int movies_count;
    cin >> movies_count;

    string high_rating_movie;
    string low_rating_movie;
    auto high_rating = DBL_MIN;
    auto low_rating = DBL_MAX;
    double total_rating = 0.0;

    for (int i = 0; i < movies_count; i++) {
        string movie_name;
        double rating;
        cin.ignore();
        getline(cin, movie_name);
        cin >> rating;

        if (rating > high_rating) {
            high_rating = rating;
            high_rating_movie = movie_name;
        } else if (rating < low_rating) {
            low_rating = rating;
            low_rating_movie = movie_name;
        }
        total_rating += rating;
    }

    cout.setf(ios::fixed);
    cout.precision(1);
    cout << high_rating_movie << " is with highest rating: " << high_rating << endl;
    cout << low_rating_movie << " is with lowest rating: " << low_rating << endl;
    cout << "Average rating: " << total_rating / movies_count << endl;

    return 0;
}
