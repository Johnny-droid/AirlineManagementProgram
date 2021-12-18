#include "Airport.h"

Airport::Airport(int id, string name) {
    this->id = id;
    this->name = name;
}

Airport::Airport(int id, string name, BST<LocalTransport> bst) {
    this->id = id;
    this->name = name;
    this->bst = bst;
}

string Airport::getName() {
    return name;
}

int Airport::getId() {
    return id;
}

BST<LocalTransport> Airport::getBST() {
    return bst;
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
    BSTItrIn it(bst);

}

