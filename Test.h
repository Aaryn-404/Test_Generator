#pragma once
#include "Id.h"
#include "QuestionContainer.h"
#include "IdContainer.h"
class Test {
private:
    string name;
    int maxPoints;
    IdContainer* questionIds;
public:
    Test(string testName, int maxPoints);
    ~Test();
    string getName();
    int getMaxPoints();
    IdContainer* getQuestionIds() { return questionIds; }
    void addQuestionId(int id);
    string toString();
};