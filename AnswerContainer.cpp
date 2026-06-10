#include "AnswerContainer.h"
AnswerContainer::AnswerContainer() : size(0), capacity(10) {
    answers = new Answer * [capacity];
}
AnswerContainer::~AnswerContainer() {
    for (int i = 0; i < size; ++i) {
        delete answers[i];
    }
    delete[] answers;
}
void AnswerContainer::resize() {
    capacity *= 2;
    Answer** newAnswers = new Answer * [capacity];
    for (int i = 0; i < size; ++i) {
        newAnswers[i] = answers[i];
    }
    delete[] answers;
    answers = newAnswers;
}
void AnswerContainer::addAnswer(string text, bool isCorrect) {
    if (size == capacity) {
        resize();
    }
    answers[size++] = new Answer(text, isCorrect);
}
string AnswerContainer::toString(){
    stringstream ss;
    for (int i = 0; i < size; ++i) {
        ss << "Answer " << (i + 1) << ": " << answers[i]->getText()
            << " (Correct: " << (answers[i]->getisCorrect() ? "Yes" : "No") << ")\n";
    }
    return ss.str();
}