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
#include "Flight.h"
#include "Service.h"
#include "LocalTransport.h"


using namespace std;

class Menu {
    vector<Airport> airports;
    vector<Passenger> passengers;
    vector<Plane> planes;

public:
    Menu(string directory);
    static void run(string directory);
    static void showMenu();
    static void showClasses();
    static int readInputMenu();
    static int readInputClasses();
    static vector<string> split(string s); //public only for tests

    void create();
    void read();
    void update();
    void remove();  //delete
    vector<Airport> getAirports();
    vector<Passenger> getPassengers();
    vector<Plane> getPlanes();
    Passenger* getPassenger(int id);
    Airport* getAirport(int id);
    Plane* getPlane(string lp);
    Plane* getPlaneWithFlightNumber(int number);
    Flight* getFlight(int number);
    void printPlanes();
    void printFlights();
    void printServices();
    void printAirports();
    void printPassengers();
    void printTickets();
    bool buyTicket(int capacity, int baggage, int price, Passenger* passenger);
    bool isPlaneLpUnique(string lp);
    bool isFlightNumberUnique(int number);
    bool isPassengerIdUnique(int id);

private:
    vector<Airport> initializeAirports(string testDirectory);
    vector<Passenger> initializePassengers(string testDirectory);
    vector<Plane> initializePlanes(string testDirectory);
    vector<queue<Service>> initializeServices(string testDirectory, string planeID);
    vector<Ticket> initializeTickets(string testDirectory, int flightID);
    vector<Flight> initializeFlights(string testDirectory, string planeLicensePlate);
};


#endif //AIRLINEMANAGEMENTPROGRAM_MENU_H
