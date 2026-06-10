#pragma once
#include "Test.h"
class TestContainer {
private:
    Test** tests;
    int size;
    int capacity;
public:
    TestContainer();
    ~TestContainer();
    void addTest(Test*);
    int getSize() { return size; }
    Test* getTestByName(string testName);
    void resize();
    bool removeTestByName(string testName);
    bool existsTest(string testName);
    string toString();
};

