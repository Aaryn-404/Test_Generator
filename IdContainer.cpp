#include "IdContainer.h"
IdContainer::IdContainer() : size(0), capacity(10) {
    ids = new Id * [capacity];
}
IdContainer::~IdContainer() {
    for (int i = 0; i < size; ++i) {
        delete ids[i];
    }
    delete[] ids;
}
void IdContainer::resize() {
    capacity *= 2;
    Id** newIds = new Id * [capacity];
    for (int i = 0; i < size; ++i) {
        newIds[i] = ids[i];
    }
    delete[] ids;
    ids = newIds;
}
void IdContainer::addId(int value) {
    if (size == capacity) { 
        resize();
    }
    ids[size++] = new Id(value);
}
int IdContainer::getSize() {
    return size;
}
string IdContainer::toString() {
    stringstream ss;
    for (int i = 0; i < size; ++i) {
        if (ids[i] != nullptr) {
            ss << ids[i]->getValue() << " ";
        }
        else {
            ss << "[null] ";
        }
    }
    return ss.str();
}
