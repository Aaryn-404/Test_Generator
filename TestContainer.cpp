#include "TestContainer.h"
TestContainer::TestContainer() : size(0), capacity(10) {
    tests = new Test * [capacity];
}
TestContainer::~TestContainer() {
    for (int i = 0; i < size; ++i) {
        delete tests[i];
    }
    delete[] tests;
}
void TestContainer::resize() {
    int newCapacity = capacity * 2;
    Test** newTests = new Test * [newCapacity];

    for (int i = 0; i < size; ++i) {
        newTests[i] = tests[i];
    }

    delete[] tests;
    tests = newTests;
    capacity = newCapacity;
}
void TestContainer::addTest(Test* test) {
    if (size == capacity) resize();
    tests[size++] = test;
}
Test* TestContainer::getTestByName(string testName) {
    for (int i = 0; i < size; ++i) {
        if (tests[i]->getName() == testName) {
            return tests[i];
        }
    }
    return nullptr;
}
bool TestContainer::removeTestByName(string testName) {
    for (int i = 0; i < size; ++i) {
        if (tests[i]->getName() == testName) {
            delete tests[i];
            for (int j = i; j < size - 1; ++j) {
                tests[j] = tests[j + 1];
            }
            --size;
            return true;
        }
    }
    return false;
}
bool TestContainer::existsTest(string testName) {
    for (int i = 0; i < size; ++i) {
        if (tests[i]->getName() == testName) {
            return true;
        }
    }
    return false;
}
string TestContainer::toString() {
    stringstream ss;
    for (int i = 0; i < size; ++i) {
        if (tests[i] != nullptr) {
            ss << tests[i]->toString() << endl;
        }
    }
    return ss.str();
}
