#include "Test.h"
Test::Test(string testName, int maxPoints) : name(testName), maxPoints(maxPoints) {
    questionIds = new IdContainer();
}
Test::~Test() {
    delete questionIds;
}
string Test::getName() {
    return name;
}
int Test::getMaxPoints() {
    return maxPoints;
}
void Test::addQuestionId(int id) {
    if (questionIds != nullptr) { 
        questionIds->addId(id);
    }
}
string Test::toString() {
    stringstream ss;
    ss << "Test Name: " << name << ", Max Points: " << maxPoints << ", Question IDs: ";
    if (questionIds != nullptr) {
        ss << questionIds->toString();
    }
    else {
        ss << "[No IDs]";
    }
    return ss.str();
}

