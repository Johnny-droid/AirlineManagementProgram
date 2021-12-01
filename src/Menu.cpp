#include "Menu.h"
#include <iostream>
#include <fstream>

using namespace std;

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
    string line, filename = "../DataFiles/Planes.txt"; //some function to determine which thing the user wants to see
    ifstream file;
    file.open(filename);

    if (!file.is_open()) {
        cout << "File didn't open" << endl;
    } else {
        cout << "\n\t\t Plane Model |  Capacity " << endl;
        while(getline(file, line)) {
            cout << "\t\t " << line << endl;
        }
        cout << endl;
    }
}

void Menu::initializeAirports(string testDirectory) {
    //Initialize the airports from the files

    /*  Work in progress
    string line;
    ifstream fileAirport, filePlanes, fileFlights;
    fileAirport.open("../DataFiles/Airports.txt");

    if (!fileAirport.is_open()) {
        throw runtime_error("File of Airports was not found");
    } else {
        while(getline(fileAirport, line)) {

        }
        cout << endl;
    }

    */
}

void Menu::initializePassengers(string testDirectory) {

}

void Menu::initializePlanes(string testDirectory) {

}



