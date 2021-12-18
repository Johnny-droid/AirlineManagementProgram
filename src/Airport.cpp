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

void Airport::setId(int newId){
    id = newId;
}

void Airport::setName(string newName){
    name = newName;
}
void Airport::print() {
    cout << "Airport " << id << ": " << name << endl;
    // Then print local transports
}

