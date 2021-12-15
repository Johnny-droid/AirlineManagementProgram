#ifndef AIRLINEMANAGEMENTPROGRAM_MENU_H
#define AIRLINEMANAGEMENTPROGRAM_MENU_H

#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <fstream>
#include "Airport.h"
#include "Plane.h"
#include "Passenger.h"

using namespace std;

class Menu {
    vector<Airport> airports;
    vector<Passenger> passengers;
    vector<Plane> planes;

public:
    Menu(string testDirectory);
    static void run();
    static void showMenu();
    static int readInputMenu();
    static void read();
    static vector<string> split(string s); //public only for tests


    vector<Airport> getAirports();
    vector<Passenger> getPassengers();
    vector<Plane> getPlanes();
    Passenger* getPassenger(int id);
    Airport* getAirport(int id);

private:
    vector<Airport> initializeAirports(string testDirectory);
    vector<Passenger> initializePassengers(string testDirectory);
    vector<Plane> initializePlanes(string testDirectory);
    queue<Service> initializeServices(string testDirectory, string planeID);
    vector<Ticket> initializeTickets(string testDirectory, int flightID);
    vector<Flight> initializeFlights(string testDirectory, string planeLicensePlate);
};


#endif //AIRLINEMANAGEMENTPROGRAM_MENU_H
