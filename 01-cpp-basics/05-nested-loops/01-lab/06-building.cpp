//
// Created by anton.petrov on 18.12.2024.
//

#include <iostream>

int main() {
    int floors, rooms;
    std::cin >> floors >> rooms;

    for (int i = floors; i > 0; i--) {
        char label;
        for (int j = 0; j < rooms; j++) {
            if (i == floors) label = 'L';
            else if (i % 2 == 0) label = 'O';
            else label = 'A';

            std::cout << label << i << j << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
