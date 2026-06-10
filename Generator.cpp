#include "Generator.h"
using namespace std;
Generator::Generator() {
    selectedIds = new IdContainer();
}
Generator::~Generator() {
    delete selectedIds;
}
void Generator::generateTest(QuestionContainer* questionContainer, Test* test) {
    int currentPoints = 0;
    int maxPoints = test->getMaxPoints();
    bool hasAvailableQuestions = false;
    for (int i = 0; i < questionContainer->getSize(); ++i) {
        Question* question = questionContainer->getQuestionAt(i);
        if (question == nullptr) {
            continue;
        }
        if (currentPoints + question->getPoints() <= maxPoints && question->getUses() < 3) {
            hasAvailableQuestions = true;
            break;
        }
    }
    if (!hasAvailableQuestions) {
        return;
    }
    for (int i = 0; i < questionContainer->getSize(); ++i) {
        Question* question = questionContainer->getQuestionAt(i);
        if (question == nullptr) {
            continue;
        }
        if (currentPoints + question->getPoints() <= maxPoints && question->getUses() < 3) {
            question->getId()->getValue();
            test->addQuestionId(question->getId()->getValue());
            question->incrementUses();
            currentPoints += question->getPoints();
        }
        if (currentPoints == maxPoints) {
            break;
        }
    }
}


