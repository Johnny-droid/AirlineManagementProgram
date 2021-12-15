#include "Passenger.h"

Passenger::Passenger(string fileString) {
    int pos1 = fileString.find_first_of(',');
    int pos2 = fileString.find_last_of(',');

    this->id = stoi(fileString.substr(0, pos1));
    this->name = fileString.substr(pos1+1, pos2 - pos1 - 1);
    this->age = stoi(fileString.substr(pos2+1));
}

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


