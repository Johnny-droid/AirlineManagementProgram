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

