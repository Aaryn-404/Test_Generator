#pragma once
#include "TestContainer.h"
#include "QuestionContainer.h"
#include "IdContainer.h"
#include "AnswerContainer.h"
class Generator {
private:
    IdContainer* selectedIds;
public:
    Generator();
    ~Generator();
    void generateTest(QuestionContainer* questionContainer, Test* test);
};
