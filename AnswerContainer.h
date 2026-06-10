#pragma once
#include "Answer.h"
class AnswerContainer {
private:
    Answer** answers;
    int size;
    int capacity;
public:
    AnswerContainer();
    void resize();
    ~AnswerContainer();
    void addAnswer(string text, bool isCorrect);
    string toString();
};

