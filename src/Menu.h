#ifndef AIRLINEMANAGEMENTPROGRAM_MENU_H
#define AIRLINEMANAGEMENTPROGRAM_MENU_H

#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Airport.h"
#include "Plane.h"
#include "Passenger.h"
#include "Flight.h"
#include "Service.h"
#include "LocalTransport.h"


using namespace std;

class Menu {
    string directory;
    string directorySave;
    vector<Airport> airports;
    vector<Passenger> passengers;
    vector<Plane> planes;

public:
    Menu();
    Menu(string directory);
    Menu(string directory, string directorySave);
    void run();
    void save();
    static void showMenu();
    static void showClasses();
    static int readInputMenu();
    static int readInputClasses();
    static int readInt();
    static string readString();
    static vector<string> split(string s); //public only for tests

    void create();
    void read();
    void update();
    void remove();  //delete

    vector<Airport>& getAirports();
    vector<Passenger>& getPassengers();
    vector<Plane>& getPlanes();
    vector<Flight> getAllFlights();
    Passenger* getPassenger(int id);
    Airport* getAirport(int id);
    Plane* getPlane(string lp);
    Plane* getPlaneWithFlightNumber(int number);
    Flight* getFlight(int number);
    void readPlanes();
    void readFlights();
    void readServices();
    void readAirports();
    void readPassengers();
    void readTickets();
    void readLocalTransports();
    void printPlanes();
    void printFlights();
    void printServices();
    void printAirports();
    void printPassengers();
    void printTickets();
    void printLocalTransports();
    bool buyTicket(int capacity, int baggage, int price, Passenger* passenger);
    bool isPlaneLpUnique(string lp);
    bool isFlightNumberUnique(int number);
    bool isPassengerIdUnique(int id);
    bool isAirportIdUnique(int id);

private:
    BST<LocalTransport> initializeLocalTransports(int idAirport);
    vector<Airport> initializeAirports();
    vector<Passenger> initializePassengers();
    vector<Plane> initializePlanes();
    vector<queue<Service>> initializeServices(string planeID);
    vector<Ticket> initializeTickets(int flightID);
    vector<Flight> initializeFlights(string planeLicensePlate);
    void savePlanes();
    void saveAirports();
    void savePassengers();
    void saveFlights();
    void saveServices();
    void saveTickets();
    void saveLocalTransports();
    void pressAnyKeyToContinue();
};


#endif //AIRLINEMANAGEMENTPROGRAM_MENU_H
