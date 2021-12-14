#ifndef AIRLINEMANAGEMENTPROGRAM_MENU_H
#define AIRLINEMANAGEMENTPROGRAM_MENU_H

#include <vector>
#include <string>
#include "Airport.h"
#include "Plane.h"
#include "Passenger.h"

using namespace std;

class Menu {
    vector<Airport> airports;
    vector<Passenger> passengers;
    vector<Plane> planes;

public:
    Menu(string testDirectory) {initializePassengers(testDirectory); initializeAirports(testDirectory); initializePlanes(testDirectory);};
    static void run();
    static void showMenu();
    static int readInputMenu();
    static void read();

private:
    void initializeAirports(string testDirectory);
    void initializePassengers(string testDirectory);
    void initializePlanes(string testDirectory);
};


#endif //AIRLINEMANAGEMENTPROGRAM_MENU_H
