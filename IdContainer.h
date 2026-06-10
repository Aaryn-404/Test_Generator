#pragma once
#include "Id.h"
class IdContainer {
private:
    Id** ids;
    int size;
    int capacity;
public:
    IdContainer();
    ~IdContainer();
    void addId(int value);
    void resize();
    int getSize();
    string toString();
};


