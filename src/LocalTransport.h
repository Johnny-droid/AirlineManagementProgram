#ifndef AIRLINEMANAGEMENTPROGRAM_LOCALTRANSPORT_H
#define AIRLINEMANAGEMENTPROGRAM_LOCALTRANSPORT_H

#include <string>
#include <iostream>

using namespace std;

class LocalTransport {
    string typeTransport;
    string times; //Ainda n sei bem o que fazer em relação a isto, mas talvez colocar uma lista de horário em que passa por dia
    int distanceToAirport;

public:
    LocalTransport();
    LocalTransport(string typeTransport, string times, int distanceToAirport);
    string getTypeTransport();
    string getTimes() const;
    int getDistanceToAirport() const;
    void setTypeTransport(string newTypeTransport);
    void setTimes(string newTimes);
    void setDistanceToAirport(int newDistanceToAirport);
    void print() const;

    bool operator<(const LocalTransport& lT) const;
};


#endif //AIRLINEMANAGEMENTPROGRAM_LOCALTRANSPORT_H
