#include "Passenger.h"

Passenger::Passenger(int id, string name, int age) {
    this->id = id;
    this->name = name;
    this->age = age;
}

int Passenger::getId() {
    return id;
}

string Passenger::getName() {
    return name;
}

int Passenger::getAge() {
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


