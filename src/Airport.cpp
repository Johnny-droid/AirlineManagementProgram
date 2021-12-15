#include "Airport.h"

Airport::Airport(string fileString) {
    this->id = stoi( fileString.substr(0, fileString.find_first_of(',')) );
    this->name = fileString.substr(fileString.find_first_of(',')+1);
}

string Airport::getName() {
    return name;
}

int Airport::getID() {
    return id;
}

