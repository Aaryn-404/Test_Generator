#include "Id.h"
#include <iostream>
Id::Id(int value) {
    this->value = value;
}
Id::~Id() {

}
int Id::getValue(){
    return value;
}

