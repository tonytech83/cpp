//
// Created by tonytech on 23.8.2025.
//

#ifndef CPP_SOLFEGENOTENAMING_H
#define CPP_SOLFEGENOTENAMING_H

#include <string>
#include "NoteName.h"


struct SolfegeNoteNaming {
    auto operator()(const std::string &noteText) const -> NoteName;
};


#endif // CPP_SOLFEGENOTENAMING_H
