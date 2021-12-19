#include "Passenger.h"

Passenger::Passenger(int id, string name, int age) {
    this->id = id;
    this->name = name;
    this->age = age;
}

int Passenger::getId() const {
    return id;
}

string Passenger::getName() const {
    return name;
}

int Passenger::getAge() const {
    return age;
}

void Passenger::setId(int newId){
    id = newId;
}
void Passenger::setName(string newName){
    name = newName;
}
void Passenger::setAge(int newAge){
    age = newAge;
}

void Passenger::print() {
    cout << "Passenger ID: " << id << "   Name: " << name << "   Age: " << age << endl;
}

bool Passenger::compareById(const Passenger &passenger1, const Passenger &passenger2) {
    return passenger1.id < passenger2.id;
}

bool Passenger::compareByName(const Passenger &passenger1, const Passenger &passenger2) {
    return passenger1.name < passenger2.name;
}

bool Passenger::compareByAge(const Passenger &passenger1, const Passenger &passenger2) {
    return passenger1.age < passenger2.age;
}


