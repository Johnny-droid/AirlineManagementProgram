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
    string getTypeTransport();
    string getTimes();
    int getDistanceToAirport();
};


#endif //AIRLINEMANAGEMENTPROGRAM_LOCALTRANSPORT_H
