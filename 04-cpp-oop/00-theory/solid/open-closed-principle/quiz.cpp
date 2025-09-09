//
// Created by tonytech on 09.09.2025.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum QuestionTypes {
    Boolean,
    SingleChoice,
    MultipleChoice,
    // Text
};

class Quiz {
    struct Question {
        QuestionTypes type{Boolean};
        string question{""};
        vector<string> answers{};
        vector<bool> correctAnswers{};

        Question() = default;
        Question(QuestionTypes _type, string _question) : type(_type), question(_question) {}
        Question(QuestionTypes _type, string _question, vector<string> _answers, vector<bool> _correctAnswers) :
            type(_type), question(_question), answers(_answers), correctAnswers(_correctAnswers) {}
    };

    vector<Question> m_questions;

public:
    Quiz() {
        m_questions.emplace_back(Question(Boolean, "Is 1MB == 1MiB", {"Yes", "No"}, {false, true}));
        m_questions.emplace_back(Question(SingleChoice, "What is the ascii code of character 'A'?",
                                          {"45", "68", "97", "65"}, {0, 0, 0, 1}));
        m_questions.emplace_back(
                Question(MultipleChoice, "Which are correct?",
                         {"Type 'int' is always 32bit.", "OCP is one of the SOLID principles.",
                          "Singleton is one of the SOLID principles.", "Assembly is programing language."},
                         {0, 1, 0, 1}));
        // m_questions.emplace_back(Question(Text, "How many bits are there in Question struct?", {"8192"}, {1}));
    }
    auto start() -> void {
        for (size_t i(0); i < m_questions.size(); i++) {
            const QuestionTypes type = m_questions.at(i).type;
            cout << m_questions.at(i).question << endl;
            switch (type) {
                case Boolean: {
                    string input{""};
                    cin >> input;
                    if (input == "True" || input == "Yes")
                        cout << "Wrong" << endl;
                    else if (input == "False" || input == "No")
                        cout << "Correct" << endl;
                    else
                        cout << "Not answered!" << endl;
                } break;
                case SingleChoice: {
                    for (size_t j(0); j < m_questions.at(i).answers.size(); j++)
                        cout << m_questions.at(i).answers.at(j) << endl;
                    string input{""};
                    cin >> input;
                    if (input == "65")
                        cout << "Correct!" << endl;
                    else
                        cout << "Wrong!" << endl;
                } break;
                case MultipleChoice: {
                    for (size_t j(0); j < m_questions.at(i).answers.size(); j++)
                        cout << "[" << to_string(j + 1) << "] " << m_questions.at(i).answers.at(j) << endl;
                    string input{""};
                    cin >> input;
                    if (input == "2,4")
                        cout << "Correct!" << endl;
                    else
                        cout << "Wrong!" << endl;
                } break;
                    // case Text: {
                    //     string input{""};
                    //     cin >> input;
                    //     if (input == "8129")
                    //         cout << "Correct!" << endl;
                    //     else
                    //         cout << "Wrong!" << endl;
                    // } break;
                default:
                    break;
            }
        }
    }
};


auto main() -> int {
    Quiz quiz;
    quiz.start();
    return 0;
}
