#pragma once
#include "Id.h"
#include "AnswerContainer.h"
class Question {
private:
    Id* id;
    string text;
    int points;
    AnswerContainer* answers;
    int uses;
public:
    Question(int idValue, string questionText, int questionPoints);
    ~Question();
    Id* getId();
    string getText();
    int getPoints();
    int getUses();
    void setText(string questionText);
    void incrementUses();
    void addAnswer(string answerText, bool isCorrect);
    string toString();
};





