#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Id {
private:
    int value;
public:
    Id(int value);
    ~Id();
    int getValue();
};

