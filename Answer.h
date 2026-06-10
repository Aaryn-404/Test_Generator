#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Answer {
private:
    string text;
    bool isCorrect;
public:
    Answer(string answerText, bool correct);
    ~Answer();
    string getText();
    bool getisCorrect();
    void setText(string answerText);
    void setIsCorrect(bool correct);
};




