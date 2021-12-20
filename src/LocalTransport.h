#ifndef AIRLINEMANAGEMENTPROGRAM_LOCALTRANSPORT_H
#define AIRLINEMANAGEMENTPROGRAM_LOCALTRANSPORT_H

#include <string>
#include <iostream>
#include <vector>
#include "Date.h"
#include "Time.h"

using namespace std;

class LocalTransport {
    int id;
    string typeTransport;
    vector<Time> times;
    int distanceToAirport;

public:
    LocalTransport();
    LocalTransport(int id, string typeTransport, string strTimes, int distanceToAirport);
    int getId() const;
    string getTypeTransport() const;
    string getStringTimes() const;
    vector<Time>& getTimes();
    int getDistanceToAirport() const;
    void setTypeTransport(string newTypeTransport);
    void setTimes(string newTimes);
    void setDistanceToAirport(int newDistanceToAirport);
    void print() const;

    bool operator<(const LocalTransport& lT) const;
    bool operator==(const LocalTransport& lT) const;
};


#endif //AIRLINEMANAGEMENTPROGRAM_LOCALTRANSPORT_H
