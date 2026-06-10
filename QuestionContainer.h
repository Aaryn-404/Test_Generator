#pragma once
#include "Question.h"
class QuestionContainer {
private:
    Question** questions;
    int size;
    int capacity;
    int nextId;
public:
    QuestionContainer();
    QuestionContainer(int initialCapacity);
    ~QuestionContainer();
    void resize();
    void addQuestion(string questionText, int questionPoints);
    Question* getQuestionAt(int index);
    Question* getQuestionById(int idValue);
    int getSize() { return size; }
    int getNextId() { return nextId; }
    string toString();
};

