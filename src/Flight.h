#ifndef AIRLINEMANAGEMENTPROGRAM_FLIGHT_H
#define AIRLINEMANAGEMENTPROGRAM_FLIGHT_H

#include <string>
#include <vector>
#include "Date.h"
#include "Airport.h"
#include "Ticket.h"

using namespace std;

class Flight {
    int number;
    int duration;
    Date dateDeparture;
    Airport* origin;
    Airport* destiny;
    vector<Ticket> tickets;
    int stackMax;
    int carriageMaxSize;
    int cartMaxSize;

public:
    Flight(int number, int duration, Airport* origin, Airport* destiny, string date);
    Flight(int number, int duration, Airport* origin, Airport* destiny, string date, vector<Ticket> tickets);
    Flight(int number, int duration, Airport *origin, Airport *destiny, string date, vector<Ticket> tickets, int stackMax, int carriageMaxSize, int cartMaxSize);
    vector<vector<vector<stack<int>>>> buildCarts();
    int getNumber() const;
    int getDuration() const;
    int getStackMax();
    int getCarriageMax();
    int getCartMax();
    Date& getDate();
    Airport* getOrigin();
    Airport* getDestiny();
    vector<Ticket>& getTickets();
    void setNumber(int newNumber);
    void setDuration(int newDuration);
    void setAirportOrigin(Airport* airport);
    void setAirportDestiny(Airport* airport);
    void print();
    void printTickets();
    void printCarts(vector<vector<vector<stack<int>>>> carts);

    static bool compareByNumber(const Flight& flight1, const Flight& flight2);
    static bool compareByDuration(const Flight& flight1, const Flight& flight2);
    static bool compareByDate(Flight& flight1, Flight& flight2);
    static bool compareByNumberTickets(Flight& flight1, Flight& flight2);
};


#endif //AIRLINEMANAGEMENTPROGRAM_FLIGHT_H
