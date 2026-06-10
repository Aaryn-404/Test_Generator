#include "QuestionContainer.h"
#include "Question.h"
#include <sstream>
#include <iostream>
QuestionContainer::QuestionContainer() {
    questions = nullptr;
    size = 0;
    capacity = 10;
    nextId = 1;
    questions = new Question * [capacity];
}
QuestionContainer::QuestionContainer(int initialCapacity)
    : capacity(initialCapacity), size(0), nextId(1) {
    questions = new Question * [capacity];
}
QuestionContainer::~QuestionContainer() {
    for (int i = 0; i < size; ++i) {
        delete questions[i];
    }
    delete[] questions;
}
void QuestionContainer::resize() {
    capacity *= 2;
    Question** newQuestions = new Question * [capacity];
    for (int i = 0; i < size; ++i) {
        newQuestions[i] = questions[i];
    }
    delete[] questions;
    questions = newQuestions;
}
void QuestionContainer::addQuestion(string questionText, int questionPoints) {
    if (size == capacity) {
        resize();
    }
    questions[size++] = new Question(nextId, questionText, questionPoints);
    ++nextId;
}
Question* QuestionContainer::getQuestionById(int idValue) {
    for (int i = 0; i < size; ++i) {
        if (questions[i]->getId()->getValue() == idValue) {
            return questions[i];
        }
    }
    return nullptr;
}
Question* QuestionContainer::getQuestionAt(int i) {
    if (i >= 0 && i < size) {
        return questions[i];
    }
    return nullptr;
}
string QuestionContainer::toString() {
    stringstream ss;
    for (int i = 0; i < size; ++i) {
        ss << "Question " << (i + 1) << ":\n" << questions[i]->toString() << "\n";
    }
    return ss.str();
}
