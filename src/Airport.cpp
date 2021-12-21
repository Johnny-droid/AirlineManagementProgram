#include "Airport.h"
/**
 * Creates an airport object with an empty binary search tree for local transports
 * @param id The airport's ID
 * @param name The airport's name
 */
Airport::Airport(int id, string name) {
    this->id = id;
    this->name = name;
}
/**
 * Creates an airport object
 * @param id The airport's ID
 * @param name The airport's name
 * @param bst A binary tree with local transport objects
 */
Airport::Airport(int id, string name, BST<LocalTransport> bst) {
    this->id = id;
    this->name = name;
    this->bst = bst;
}
/**
 *
 * @return The airport's name
 */
string Airport::getName() const {
    return name;
}
/**
 *
 * @return The airport's ID
 */
int Airport::getId() const {
    return id;
}
/**
 *
 * @return The binary search tree with local tranport objects
 */
BST<LocalTransport>& Airport::getBST() {
    return bst;
}
/**
 * Changes the airport's ID to a new one
 * @param newId The new ID
 */
void Airport::setId(int newId){
    id = newId;
}
/**
 * Change's the airport's name to a new one
 * @param newName The new name
 */
void Airport::setName(string newName){
    name = newName;
}
/**
 * Print that represents the airport object by showing its ID, name and the size of its binary search tree
 */
void Airport::print() {
    cout << "Airport " << id << ": " << name << "    Number of Local Transports: " << this->getBSTSize() << endl;
}
/**
 * From the airport's binary search tree, prints all local transports by showing their IDs, names, timetable and distance to airport
 */
void Airport::printLocalTransports() {
    BSTItrIn<LocalTransport> itrIn(bst);
    while (!itrIn.isAtEnd()) {
        itrIn.retrieve().print();
        itrIn.advance();
    }
}
/**
 * Check is a certain ID already belongs to a local transport of the airport's BST
 * @param id An ID that we want to know if it belongs to a local transport from the BST
 * @return True, if the ID exists in a local transport object from the BST. False, if otherwise.
 */
bool Airport::isLocalTransportId(int id) {
    BSTItrIn<LocalTransport> it(bst);
    while (!it.isAtEnd()) {
        if (it.retrieve().getId() == id) return true;
        it.advance();
    }
    return false;
}
/**
 * Goes through every node of the Binary Search Tree and for each these, adds 1 to a counter
 * @return The size of the airport's Binary Search Tree
 */
int Airport::getBSTSize() const {
    int counter = 0;
    BSTItrIn it(bst);
    while (!it.isAtEnd()) {
        counter++;
        it.advance();
    }
    return counter;
}
/**
 * Compares two airports by ID
 * @param airport1 The first airport
 * @param airport2 The second airport
 * @return True, if the first airport's ID number is smaller than the second airport's. False, if otherwise.
 */
bool Airport::compareById(const Airport &airport1, const Airport &airport2) {
    return airport1.id < airport2.id;
}
/**
 * Compares two airports by name
 * @param airport1 The first airport
 * @param airport2 The second airport
 * @return True, if the first airport's name is alphabetically before the second airport's. False, if otherwise.
 */
bool Airport::compareByName(const Airport &airport1, const Airport &airport2) {
    return airport1.name < airport2.name;
}
/**
 * Compares two airports by the size of their binary search trees of local transports
 * @param airport1 The first airport
 * @param airport2 The second airport
 * @return True, if the first airport's binary search tree has a smaller size than the second airport's. False, if otherwise.
 */
bool Airport::compareByNumberLocalTransports(const Airport &airport1, const Airport &airport2) {
    return airport1.getBSTSize() < airport2.getBSTSize();
}

