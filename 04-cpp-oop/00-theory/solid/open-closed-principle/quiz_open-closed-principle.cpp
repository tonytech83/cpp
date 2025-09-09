//
// Created by tonytech on 09.09.2025.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Question {


public:
    string question;
    vector<string> answers{};
    vector<bool> correctAnswers{};

    Question() = default;
    explicit Question(string _question) : question(std::move(_question)) {}
    Question(string _question, const vector<string> &_answers, const vector<bool> &_correctAnswers) :
        question(std::move(_question)), answers(_answers), correctAnswers(_correctAnswers) {}

    virtual auto showQuestion(const int id) -> void { cout << "[Question " + to_string(id) + "] " << question << endl; }
    virtual auto showAnswers() -> void {}
    virtual auto checkCorrectAnswers() -> void {}

    virtual ~Question() = default;
};

struct Boolean final : Question {
    Boolean(const string &_question, const vector<string> &_answers, const vector<bool> &_correctAnswers) :
        Question(_question, _answers, _correctAnswers) {}

    auto showAnswers() -> void override {
        cout << "Chose the correct: " << answers.at(0) << "/" << answers.at(1) << endl;
    }
    auto checkCorrectAnswers() -> void override {
        cout << ">>";
        string input;
        cin >> input;
        int answerIndex;
        if (input == "Yes")
            answerIndex = 0;
        else if (input == "No")
            answerIndex = 1;
        else {
            cout << input << "Not answered!" << endl;
            return;
        }

        if (correctAnswers.at(answerIndex))
            cout << "Correct!" << endl;
        else
            cout << "Wrong!" << endl;
    }
};

struct SingleChoice final : Question {
    SingleChoice(const string &_question, const vector<string> &_answers, const vector<bool> &_correctAnswers) :
        Question(_question, _answers, _correctAnswers) {}

    auto showAnswers() -> void override {
        for (const auto &answer: answers)
            cout << answer << endl;
    }

    auto checkCorrectAnswers() -> void override {
        cout << ">> ";
        string input;
        cin >> input;
        bool flag = false;
        for (size_t i(0); i < answers.size(); i++)
            if (input == answers.at(i))
                if (correctAnswers.at(i))
                    flag = true;

        if (flag)
            cout << "Correct!" << endl;
        else
            cout << "Wrong!" << endl;
    }
};

struct MultipleChoice final : Question {
    MultipleChoice(const string &_question, const vector<string> &_answers, const vector<bool> &_correctAnswers) :
        Question(_question, _answers, _correctAnswers) {}

    static auto ltrim(string &s) -> void {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isspace(c); }));
    }
    static auto rtrim(string &s) -> void {
        s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !std::isspace(c); }).base(), s.end());
    }

    static auto trim(string &s) -> void {
        ltrim(s);
        rtrim(s);
    }

    static auto split(const string &s, const string &delimiter) -> vector<string> {
        size_t pos_start = 0, pos_end;
        const size_t delim_len = delimiter.length();
        string token;
        vector<string> res;

        while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }

        res.push_back(s.substr(pos_start));
        return res;
    }

    auto showAnswers() -> void override {
        for (size_t j(0); j < answers.size(); j++)
            cout << "[" + to_string(j + 1) + "] " + answers.at(j) << endl;
    }

    auto checkCorrectAnswers() -> void override {
        cout << ">> ";
        string input;
        cin >> input;
        vector<bool> flags;
        vector<int> givenAnswers;
        try {
            vector<string> list = split(input, ",");
            for (const auto &i: list)
                givenAnswers.push_back(stoi(i) - 1);
        } catch (exception &e) {
            return;
        }

        flags.resize(givenAnswers.size());

        for (const int givenAnswer: givenAnswers) {
            for (size_t i(0); i < correctAnswers.size(); i++)
                if (givenAnswer == correctAnswers.at(i))
                    flags.at(i) = true;
        }

        bool isCorrect{true};
        for (size_t i(0); i < flags.size(); i++)
            if (flags.at(i) != correctAnswers.at(i))
                isCorrect = false;

        if (isCorrect)
            cout << "Correct" << endl;
        else
            cout << "Wrong" << endl;
    }
};

struct Text final : Question {
    Text(const string &_question, const vector<string> &_answers, const vector<bool> &_correctAnswers) :
        Question(_question, _answers, _correctAnswers) {}

    auto checkCorrectAnswers() -> void override {
        cout << ">> ";
        string input;
        cin >> input;
        if (input == answers.front())
            cout << "Correct!" << endl;
        else
            cout << "Wrong!" << endl;
    }
};

class Quiz {
    vector<Question *> m_questions;

public:
    Quiz() {
        m_questions.emplace_back(new Boolean("Is 1MB == 1MiB", {"Yes", "No"}, {false, true}));
        m_questions.emplace_back(new SingleChoice("What is the ascii code of character 'A'?", {"45", "68", "97", "65"},
                                                  {false, false, false, true}));
        m_questions.emplace_back(
                new MultipleChoice("Which are correct?",
                                   {"Type 'int' is always 32bit.", "OCP is one of the SOLID principles.",
                                    "Singleton is one of the SOLID principles.", "Assembly is programing language."},
                                   {false, true, false, true}));
        m_questions.emplace_back(new Text("How many bits are there in Question struct?", {"8192"}, {true}));
    }

    auto start() const -> void {
        for (size_t i(0); i < m_questions.size(); i++) {
            m_questions.at(i)->showQuestion(static_cast<int>(i) + 1);
            m_questions.at(i)->showAnswers();
            m_questions.at(i)->checkCorrectAnswers();
            cout << "--------------------------------------------------" << endl;
        }
    }
};

auto main() -> int {
    const Quiz q;
    q.start();

    return 0;
}
