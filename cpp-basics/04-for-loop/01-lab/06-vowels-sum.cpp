//
// Created by tonytech on 12/15/2024.
//
#include <iostream>
#include <string>

int main() {
    std::string text;
    std::getline(std::cin, text);

    int sum = 0;

//    for (int i = 0; i < text.length(); i++) {
//        if (text[i] == 'a') sum += 1;
//        else if (text[i] == 'e') sum += 2;
//        else if (text[i] == 'i') sum += 3;
//        else if (text[i] == 'o') sum += 4;
//        else if (text[i] == 'u') sum += 5;
//    }

    for (const auto c: text) {
       switch (c) {
           case 'a': sum += 1; break;
           case 'e': sum += 2; break;
           case 'i': sum += 3; break;
           case 'o': sum += 4; break;
           case 'u': sum += 5; break;
           default:;
       }
    }

    std::cout << sum << std::endl;

    return 0;
}