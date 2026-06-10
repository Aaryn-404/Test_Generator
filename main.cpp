#include <iostream>
#include "Generator.h"
using namespace std;

void requestCreateQuestion(QuestionContainer* questionContainer) {
    string questionText;
    int questionPoints;
    cout << "Enter the question text: ";
    cin.ignore();
    getline(cin, questionText);
    cout << "Enter the points for this question: ";
    cin >> questionPoints;
    questionContainer->addQuestion(questionText, questionPoints);
    Question* newQuestion = questionContainer->getQuestionAt(questionContainer->getSize() - 1);
    if (newQuestion == nullptr) {
        cout << "Unable to retrieve the newly created question." << endl;
        return;
    }
    int numAnswers;
    cout << "Enter the number of answers for this question: ";
    cin >> numAnswers;
    cin.ignore();
    for (int i = 0; i < numAnswers; ++i) {
        string answerText;
        bool isCorrect;
        cout << "Enter text for answer " << (i + 1) << ": ";
        getline(cin, answerText);
        cout << "Is this answer correct? (1 for Yes, 0 for No): ";
        cin >> isCorrect;
        cin.ignore();
        newQuestion->addAnswer(answerText, isCorrect);
    }
    cout << "Question created successfully." << endl;
}
void requestTestGeneration(Generator* generator, QuestionContainer* questionContainer, TestContainer* testContainer) {
    string testName;
    int maxPoints;
    cout << "Enter the test name: ";
    cin.ignore();
    getline(cin, testName);
    cout << "Enter the maximum points for the test: ";
    cin >> maxPoints;
    if (testContainer->existsTest(testName)) {
        cout << "A test with this name already exists." << endl;
        return;
    }
    Test* test = new Test(testName, maxPoints);
    generator->generateTest(questionContainer, test);
    testContainer->addTest(test);
    cout << "Test generated successfully."<< endl;
}

void lookupQuestionById(QuestionContainer* questionContainer) {
    int id;
    cout << "Enter the ID of the question: ";
    cin >> id;
    Question* question = questionContainer->getQuestionById(id);
    if (question != nullptr) {
        cout << question->toString() << endl;
    }
    else {
        cout << "Question not found.";
    }
}

void lookupExamByName(TestContainer* testContainer, QuestionContainer* questionContainer) {
    string name;
    cout << "Enter the name of the test: ";
    cin.ignore();
    getline(cin, name);
    Test* test = testContainer->getTestByName(name);
    if (test != nullptr) {
        cout << test->toString() << endl;
    }
    else {
        cout << "Test not found.";
    }
}

void deleteExamByName(TestContainer* testContainer, QuestionContainer* questionContainer) {
    string name;
    cout << "Enter the name of the test to delete: ";
    cin.ignore();
    getline(cin, name);
    if (testContainer->removeTestByName(name)) {
        cout << "Test deleted successfully.";
    }
    else {
        cout << "Test not found.";
    }
}

void displayAllTests(TestContainer* testContainer) {
    if (testContainer->getSize() == 0) {
        cout << "No tests have been created yet.";
    }
    else {
        cout << testContainer->toString() << endl;
    }
}

int main() {
    Generator* generator = new Generator();
    QuestionContainer* questionContainer = new QuestionContainer();
    TestContainer* testContainer = new TestContainer();
    int choice;
    do {
        cout << "--- MAIN MENU ---"<< endl;
        cout << "1. Create a question" << endl;
        cout << "2. Request test generation" << endl;
        cout << "3. Look up a questions info" << endl;
        cout << "4. Look up a question by ID" << endl;
        cout << "5. Display tests" << endl;
        cout << "6. Look up an test by name" << endl;
        cout << "7. Delete an test by name" << endl;
        cout << "8. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            requestCreateQuestion(questionContainer);
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            break;
        case 2:
            system("cls");
            requestTestGeneration(generator, questionContainer, testContainer);
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            break;
        case 3:
            system("cls");
            cout << questionContainer->toString() << endl;
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            break;
        case 4:
            system("cls");
            lookupQuestionById(questionContainer);
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            break;
        case 5:
            system("cls");
            displayAllTests(testContainer);
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            break;
        case 6:
            system("cls");
            lookupExamByName(testContainer, questionContainer);
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            break;
        case 7:
            system("cls");
            deleteExamByName(testContainer, questionContainer);
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            break;
        case 8:
            system("cls");
            cout << "Exiting...";
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            break;
        default:
            cout << "Invalid option. Try again.";
            break;
        }
    } while (choice != 8);
    delete generator;
    delete questionContainer;
    delete testContainer;
    return 0;
}
