#include "Airport.h"

Airport::Airport(int id, string name) {
    this->id = id;
    this->name = name;
}

string Airport::getName() {
    return name;
}

int Airport::getId() {
    return id;
}

