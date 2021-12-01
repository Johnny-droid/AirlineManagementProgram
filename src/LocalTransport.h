#ifndef AIRLINEMANAGEMENTPROGRAM_LOCALTRANSPORT_H
#define AIRLINEMANAGEMENTPROGRAM_LOCALTRANSPORT_H

#include <string>

using namespace std;

class LocalTransport {
    string typeTransport;
    string times; //Ainda n sei bem o que fazer em relação a isto, mas talvez colocar uma lista de horário em que passa por dia
    int distanceToAirport;

public:
    LocalTransport(string typeTransport, string times, int distanceToAirport);
    string getTypeTransport() {return typeTransport;};
    string getTimes() {return times;};
    int getDistanceToAirport() {return distanceToAirport;};
};


#endif //AIRLINEMANAGEMENTPROGRAM_LOCALTRANSPORT_H
