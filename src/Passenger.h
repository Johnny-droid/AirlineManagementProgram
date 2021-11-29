#ifndef AIRLINEMANAGEMENTPROGRAM_PASSENGER_H
#define AIRLINEMANAGEMENTPROGRAM_PASSENGER_H

#include <string>

using namespace std;

class Passenger {
    string name;
    int baggage; //talvez adicionar mais atributos como informações pessoais
public:
    Passenger(string name, int baggage);
    string getName();
    int getBaggage();
};


#endif //AIRLINEMANAGEMENTPROGRAM_PASSENGER_H
