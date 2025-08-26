//
// Created by tonytech on 23.8.2025.
//

#include "SolfegeNoteNaming.h"

auto SolfegeNoteNaming::operator()(const std::string &noteText) const -> NoteName {
    if (noteText == "Do")
        return {'C'};
    if (noteText == "Re")
        return {'D'};
    if (noteText == "Mi")
        return {'E'};
    if (noteText == "Fa")
        return {'F'};
    if (noteText == "Sol")
        return {'G'};
    if (noteText == "La")
        return {'A'};
    if (noteText == "Si")
        return {'B'};
    return {'?'};
}
