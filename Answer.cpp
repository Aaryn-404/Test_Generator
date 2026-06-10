#include "Answer.h"
Answer::Answer(string answerText, bool correct)
    : text(answerText), isCorrect(correct) {}
Answer::~Answer() {}
string Answer::getText() {
    return text;
}
bool Answer::getisCorrect() {
    return isCorrect;
}
void Answer::setText(string answerText) {
    text = answerText;
}
void Answer::setIsCorrect(bool correct) {
    isCorrect = correct;
}