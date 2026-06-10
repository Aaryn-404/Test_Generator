#include "Question.h"
Question::Question(int id_value, string questionText, int questionPoints)
    : text(questionText), points(questionPoints), uses(0) {
    id = new Id(id_value);
    answers = new AnswerContainer();
}
Question::~Question() {
    delete id;
    delete answers;
}
Id* Question::getId() {
    return id;
}
string Question::getText() {
    return text;
}
int Question::getPoints() {
    return points;
}
int Question::getUses() {
    return uses;
}
void Question::setText(string questionText) {
    text = questionText;
}
void Question::incrementUses() {
    ++uses;
}
void Question::addAnswer(string answerText, bool isCorrect) {
    answers->addAnswer(answerText, isCorrect);
}
string Question::toString() {
    stringstream ss;
    ss << "Question ID: " << id->getValue() << endl
        << "Text: " << text << endl
        << "Points: " << points << endl
        << "Uses: " << uses << endl
        << "Answers:\n" << answers->toString();
    return ss.str();
}
