#include "Menu.h"
#include <iostream>
#include <fstream>

using namespace std;

Menu::Menu(string testDirectory) {
    this->airports = initializeAirports(testDirectory);
    this->passengers = initializePassengers(testDirectory);
    this->planes = initializePlanes(testDirectory);
}

void Menu::run() {
    int option;
    do {
        showMenu();
        option = readInputMenu();

        //makes switch clauses
        //read();

    } while (option != 0);

}


void Menu::showMenu() {
    //clear maybe if possible
    cout << "     1) Create      " << endl;
    cout << "     2) Read        " << endl;
    cout << "     3) Update      " << endl;
    cout << "     4) Delete      " << endl;
    cout << "     0) Exit        " << endl;
}

int Menu::readInputMenu() {
    // gets the option number
    int chosenOption;
    do {
        cout << "\n     Enter option: ";
        cin >> chosenOption;
        if ((chosenOption != 1 && chosenOption != 2 && chosenOption != 3 && chosenOption != 4 && chosenOption != 0) || cin.fail()) {
            if (cin.eof()) {
                exit(0);
            }
            cin.clear();
            cin.ignore(100000, '\n');
            cout << "\t\tInvalid input!\n";
        }
    } while (chosenOption != 1 && chosenOption != 2 && chosenOption != 3 && chosenOption != 4 && chosenOption != 0);
    return chosenOption;
}

void Menu::read() {

}

vector<Airport> Menu::initializeAirports(string testDirectory) {
    //Initialize the airports from the files
    ifstream fileAirport;
    string line;
    vector<Airport> airportsVector;

    fileAirport.open(testDirectory + "Airports.txt");

    if (!fileAirport.is_open()) {
        throw runtime_error("File of Airports was not found");
    } else {
        while(getline(fileAirport, line)) {
            if (line.empty()) continue;
            Airport airport(line);
            airportsVector.push_back(airport);
        }
        cout << endl;
    }

    fileAirport.close();
    return airportsVector;
}

vector<Passenger> Menu::initializePassengers(string testDirectory) {
    ifstream filePassengers;
    string line;
    vector<Passenger> passengersVector;

    filePassengers.open(testDirectory + "Passengers.txt");

    if (!filePassengers.is_open()) {
        throw runtime_error("File of Passengers was not found");
    } else {
        while(getline(filePassengers, line)) {
            if (line.empty()) continue;
            Passenger passenger(line);
            passengersVector.push_back(passenger);
        }
        cout << endl;
    }

    filePassengers.close();

    return passengersVector;
}

vector<Plane> Menu::initializePlanes(string testDirectory) {
    vector<Plane> planesVector;

    return planesVector;
}




