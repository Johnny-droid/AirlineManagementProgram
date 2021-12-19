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

string Airport::getName() const {
    return name;
}

int Airport::getId() const {
    return id;
}

BST<LocalTransport>& Airport::getBST() {
    return bst;
}

void Airport::setId(int newId){
    id = newId;
}

void Airport::setName(string newName){
    name = newName;
}
void Airport::print() {
    cout << "Airport " << id << ": " << name << "    Number of Local Transports: " << this->getBSTSize() << endl;
}

void Airport::printLocalTransports() {
    BSTItrIn<LocalTransport> itrIn(bst);
    while (!itrIn.isAtEnd()) {
        itrIn.retrieve().print();
        itrIn.advance();
    }
}

bool Airport::isLocalTransportId(int id) {
    BSTItrIn<LocalTransport> it(bst);
    while (!it.isAtEnd()) {
        if (it.retrieve().getId() == id) return true;
        it.advance();
    }
    return false;
}

int Airport::getBSTSize() const {
    int counter = 0;
    BSTItrIn it(bst);
    while (!it.isAtEnd()) {
        counter++;
        it.advance();
    }
    return counter;
}

bool Airport::compareById(const Airport &airport1, const Airport &airport2) {
    return airport1.id < airport2.id;
}

bool Airport::compareByName(const Airport &airport1, const Airport &airport2) {
    return airport1.name < airport2.name;
}

bool Airport::compareByNumberLocalTransports(const Airport &airport1, const Airport &airport2) {
    return airport1.getBSTSize() < airport2.getBSTSize();
}

