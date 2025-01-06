//
// Created by TonyTech on 6.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string movie_name, favorite_movie;
    int movies_counter = 0;
    int favorite_movie_points = 0;

    // Read the first movie name
    getline(cin, movie_name);

    // Process movies until "STOP" or the limit is reached
    while (movie_name != "STOP") {
        movies_counter++;
        int movie_points = 0;
        const int name_length = movie_name.size();

        // Calculate points for the current movie
        for (int i = 0; i < movie_name.length(); i++) {
            if (islower(movie_name[i])) {
                movie_points += movie_name[i] - 2 * name_length;
            } else if (isupper(movie_name[i])) {
                movie_points += movie_name[i] - name_length;
            } else {
                movie_points += movie_name[i];
            }
        }

        // Update the favorite movie if this one has higher points
        if (movie_points > favorite_movie_points) {
            favorite_movie_points = movie_points;
            favorite_movie = movie_name;
        }

        // Break if the movie limit is reached
        if (movies_counter == 7) {
            break;
        }

        // Read the name of the movie
        getline(cin, movie_name);
    }

    // Output results
    if (movies_counter == 7) {
        cout << "The limit is reached." << endl;
    }
    cout << "The best movie for you is " << favorite_movie << " with " << favorite_movie_points << " ASCII sum."
         << endl;

    return 0;
}
