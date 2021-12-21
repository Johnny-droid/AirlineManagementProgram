#include "Passenger.h"

/**
 * Creates a passenger object
 * @param id The passenger's identification number
 * @param name The passenger's name
 * @param age The passenger's age
 */
Passenger::Passenger(int id, string name, int age) {
    this->id = id;
    this->name = name;
    this->age = age;
}
/**
 *
 * @return The passenger's ID
 */
int Passenger::getId() const {
    return id;
}
/**
 *
 * @return The passenger's name
 */
string Passenger::getName() const {
    return name;
}
/**
 *
 * @return The passenger's age
 */
int Passenger::getAge() const {
    return age;
}
/**
 * Changes the ID to a new one
 * @param newId The new ID
 */
void Passenger::setId(int newId){
    id = newId;
}
/**
 * Changes the name to a new one
 * @param newName The new name
 */
void Passenger::setName(string newName){
    name = newName;
}
/**
 * Changes the age to a new one
 * @param newAge The new age
 */
void Passenger::setAge(int newAge){
    age = newAge;
}
/**
 * Print that represents the passenger object by showing their ID, name and age
 */
void Passenger::print() {
    cout << "Passenger ID: " << id << "   Name: " << name << "   Age: " << age << endl;
}
/**
 * Compares two passengers by their ID
 * @param passenger1 The first passenger
 * @param passenger2 The second passenger
 * @return True, if the first passenger's ID number is smaller than the second passenger's. False, if otherwise.
 */
bool Passenger::compareById(const Passenger &passenger1, const Passenger &passenger2) {
    return passenger1.id < passenger2.id;
}
/**
 * Compares two passengers by their name
 * @param passenger1 The first passenger
 * @param passenger2 The second passenger
 * @return True, if the first passenger's name is alphabetically before the second passenger's. False, if otherwise.
 */
bool Passenger::compareByName(const Passenger &passenger1, const Passenger &passenger2) {
    return passenger1.name < passenger2.name;
}
/**
 * Compares two passengers by their ID
 * @param passenger1 The first passenger
 * @param passenger2 The second passenger
 * @return True, if the first passenger is younger than the second passenger. False, if otherwise.
 */
bool Passenger::compareByAge(const Passenger &passenger1, const Passenger &passenger2) {
    return passenger1.age < passenger2.age;
}


