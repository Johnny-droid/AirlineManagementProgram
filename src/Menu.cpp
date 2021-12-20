#include "Menu.h"

using namespace std;

Menu::Menu() {
    this->directory = "";
    this->directorySave = "";
    this->airports = vector<Airport>();
    this->passengers = vector<Passenger>();
    this->planes = vector<Plane>();
}

Menu::Menu(string directory) {
    this->directory = directory;
    this->directorySave = directory;
    this->airports = initializeAirports();
    this->passengers = initializePassengers();
    this->planes = initializePlanes();
}

Menu::Menu(string directory, string directorySave) {
    this->directory = directory;
    this->directorySave = directorySave;
    this->airports = initializeAirports();
    this->passengers = initializePassengers();
    this->planes = initializePlanes();
}

void Menu::run() {
    int option;
    do {
        showMenu();
        option = readInputMenu();
        if (option == 1) create();
        else if (option == 2) read();
        else if (option == 3) update();
        else if (option == 4) remove();
        else if (option == 42) simulation();

        if (option != 0) pressAnyKeyToContinue();
    } while (option != 0);
    save();
}

void Menu::save() {
    saveAirports();
    savePlanes();
    saveFlights();
    savePassengers();
    saveTickets();
    saveServices();
    saveLocalTransports();
}

void Menu::showMenu() {
    //clear maybe if possible
    cout << "\nWhat would you like to do?" << endl;
    cout << "\n     1) Create      " << endl;
    cout << "     2) Read        " << endl;
    cout << "     3) Update      " << endl;
    cout << "     4) Delete      " << endl;
    cout << "     0) Exit        \n" << endl;
    cout << "     42) Simulation  " << endl;
}

void Menu::showClasses() {
    cout << "     1) Planes           " << endl;
    cout << "     2) Flights          " << endl;
    cout << "     3) Services         " << endl;
    cout << "     4) Airports         " << endl;
    cout << "     5) Tickets          " << endl;
    cout << "     6) Passengers       " << endl;
    cout << "     7) Local Transports " << endl;
    cout << "     0) Back             " << endl;
}


int Menu::readInputMenu() {
    // gets the option number
    int chosenOption;
    bool notValid;
    do {
        cout << "\n   Enter option: ";
        cin >> chosenOption;
        notValid = chosenOption != 1 && chosenOption != 2 && chosenOption != 3 && chosenOption != 4 && chosenOption != 42 && chosenOption != 0 ;
        if ( notValid || cin.fail()) {
            if (cin.eof()) {
                exit(0);
            }
            cin.clear();
            cin.ignore(100000, '\n');
            cout << "\t\tInvalid input!\n";
        }
    } while (notValid);
    return chosenOption;
}

int Menu::readInputClasses() {
    int chosenOption;
    bool notValid;
    do {
        cout << "\n     Enter option: ";
        cin >> chosenOption;
        notValid = chosenOption != 1 && chosenOption != 2 && chosenOption != 3 && chosenOption != 4 && chosenOption != 5 && chosenOption != 6 && chosenOption != 7 && chosenOption != 0;
        if ( notValid || cin.fail()) {
            if (cin.eof()) {
                exit(0);
            }
            cin.clear();
            cin.ignore(100000, '\n');
            cout << "\t\tInvalid input!\n";
        }
    } while (notValid);
    return chosenOption;
}

int Menu::readInt() {
    int x; bool fail;
    do {
        cin >> x;
        fail = cin.fail();
        if (fail)  {
            cout << "it failed" << endl;
            if (cin.eof()) {
                exit(0);
            }
            cin.clear();
            cin.ignore(100000, '\n');
            cout << "Invalid Input Try again: " << endl;
        }
    } while (fail);
    return x;
}

string Menu::readString() {
    string str; bool fail;
    cin.ignore(1000, '\n');  // para conseguir ler um nome de aeroporto com mais do que uma palavra
    do {
        getline(cin, str);
        fail = cin.fail();
        if (fail)  {
            if (cin.eof()) {
                exit(0);
            }
            cin.clear();
            cout << "Invalid Input Try again: " << endl;
        }
    } while (fail);
    return str;
}

vector<string> Menu::split(string s, string delimeter) {
    vector<string> v;

    while (s.length() != 0) {
        int pos = s.find_first_of(delimeter);
        if (pos == s.npos) {
            v.push_back(s);
            break;
        }
        string subStr = s.substr(0, pos);
        v.push_back(subStr);
        s = s.substr(pos + 1);
    }

    return v;
}

vector<Airport>& Menu::getAirports() {
    return airports;
}

vector<Passenger>& Menu::getPassengers() {
    return passengers;
}

vector<Plane>& Menu::getPlanes() {
    return planes;
}

vector<Flight> Menu::getAllFlights() {
    vector<Flight> flights;
    for (Plane &plane : planes) {
        for (Flight flight : plane.getFlightPlan()) {
            flights.push_back(flight);
        }
    }
    return flights;
}

vector<Ticket> Menu::getAllTickets() {
    vector<Ticket> tickets;
    for (Plane &plane : planes) {
        for (Flight &flight : plane.getFlightPlan()) {
            for (Ticket ticket : flight.getTickets()) {
                tickets.push_back(ticket);
            }
        }
    }
    return tickets;
}

Passenger *Menu::getPassenger(int id) {
    for (Passenger &passenger : passengers) {
        if (passenger.getId() == id) {
            Passenger* passengerPtr = &passenger;
            return passengerPtr;
        }
    }
    return nullptr;
}

Airport *Menu::getAirport(int id) {
    for (Airport &airport : airports) {
        if (airport.getId() == id) {
            Airport* airportPtr = &airport;
            return airportPtr;
        }
    }
    return nullptr;
}

Plane *Menu::getPlane(string lp) {
    for (Plane &plane : planes) {
        if (plane.getLicensePlate() == lp) {
            Plane* planePtr = &plane;
            return planePtr;
        }
    }
    return nullptr;
}

Plane *Menu::getPlaneWithFlightNumber(int number) {
    for (Plane &plane : planes) {
        for (Flight &flight : plane.getFlightPlan()) {
            if (flight.getNumber() == number) {
                Plane* planePtr = &plane;
                return planePtr;
            }
        }
    }
    return nullptr;
}

Flight *Menu::getFlight(int number) {
    for (Plane &plane : planes) {
        for (Flight &flight : plane.getFlightPlan()) {
            if (flight.getNumber() == number) {
                Flight* flightPtr = &flight;
                return flightPtr;
            }
        }
    }
    return nullptr;
}

BST<LocalTransport> Menu::initializeLocalTransports(int idAirport) {
    ifstream fileLT;
    string line;
    LocalTransport localTransportNotFound;
    BST<LocalTransport> bstLT(localTransportNotFound);

    fileLT.open(directory + "LocalTransports.txt");

    if (!fileLT.is_open()) {
        throw runtime_error("File of Local Transports was not found");
    } else {
        int counter = 1;
        while(getline(fileLT, line)) {
            if (line.empty()) continue;
            vector<string> elements = split(line, ",");
            if (stoi(elements[0]) == idAirport) {
                LocalTransport lT(counter, elements[1], elements[2], stoi(elements[3]));
                bstLT.insert(lT);
                counter++;
            }
        }
    }

    fileLT.close();
    return bstLT;
}

vector<Airport> Menu::initializeAirports() {
    //Initialize the airports from the files
    ifstream fileAirport;
    string line;
    vector<Airport> airportsVector;

    fileAirport.open(directory + "Airports.txt");

    if (!fileAirport.is_open()) {
        throw runtime_error("File of Airports was not found");
    } else {
        while(getline(fileAirport, line)) {
            if (line.empty()) continue;
            vector<string> elements = split(line, ",");
            BST<LocalTransport> bst = initializeLocalTransports(stoi(elements[0]));
            Airport airport(stoi(elements[0]), elements[1], bst);
            airportsVector.push_back(airport);
        }
    }

    fileAirport.close();
    return airportsVector;
}

vector<Passenger> Menu::initializePassengers() {
    ifstream filePassengers;
    string line;
    vector<Passenger> passengersVector;

    filePassengers.open(directory + "Passengers.txt");

    if (!filePassengers.is_open()) {
        throw runtime_error("File of Passengers was not found");
    } else {
        while(getline(filePassengers, line)) {
            if (line.empty()) continue;
            vector<string> elements = split(line, ",");
            Passenger passenger(stoi(elements[0]), elements[1], stoi(elements[2]));
            passengersVector.push_back(passenger);
        }
    }

    filePassengers.close();

    return passengersVector;
}

vector<queue<Service>> Menu::initializeServices(string planeID) {
    ifstream fileServices;
    string line;
    vector<queue<Service>> v;
    queue<Service> servicesCompleted, servicesToBeDone;

    fileServices.open(directory + "Services.txt");

    if (!fileServices.is_open()) {
        throw runtime_error("File of Services was not found");
    } else {
        while(getline(fileServices, line)) {
            if (line.empty()) continue;
            vector<string> elements = split(line, ",");
            if (elements[0] == planeID) {
                // converter elements[2] numa data
                Service service(elements[1], elements[2], elements[3]);
                if (elements[4] == "y") {
                    servicesCompleted.push(service);
                } else {
                    servicesToBeDone.push(service);
                }
            }
        }
    }

    fileServices.close();
    v.push_back(servicesCompleted);
    v.push_back(servicesToBeDone);
    return v;
}

vector<Ticket> Menu::initializeTickets(int flightID) {
    ifstream fileTickets;
    string line;
    vector<Ticket> ticketsVector;

    fileTickets.open(directory + "Tickets.txt");

    if (!fileTickets.is_open()) {
        throw runtime_error("File of Tickets was not found");
    } else {
        while(getline(fileTickets, line)) {
            if (line.empty()) continue;
            vector<string> elements = split(line, ",");

            if (stoi(elements[0]) == flightID) {
                Ticket ticket( stoi(elements[2]) , stoi(elements[3]), this->getPassenger(stoi(elements[1])));
                ticketsVector.push_back(ticket);
            }
        }
    }

    fileTickets.close();
    return ticketsVector;
}

vector<Flight> Menu::initializeFlights(string planeLicensePlate) {
    ifstream fileFlights;
    string line;
    vector<Flight> flightsVector;

    fileFlights.open(directory + "Flights.txt");

    if (!fileFlights.is_open()) {
        throw runtime_error("File of Flights was not found");
    } else {
        while(getline(fileFlights, line)) {
            if (line.empty()) continue;
            vector<string> elements = split(line, ",");

            if (elements[1] == planeLicensePlate) {
                Airport* origin = this->getAirport(stoi(elements[2]));
                Airport* destiny = this->getAirport(stoi(elements[3]));
                vector<Ticket> tickets = initializeTickets(stoi(elements[0]));
                Flight flight(stoi(elements[0]), stoi(elements[4]), origin, destiny, elements[5] , tickets);
                flightsVector.push_back(flight);
            }
        }
    }

    fileFlights.close();

    return flightsVector;
}

vector<Plane> Menu::initializePlanes() {
    ifstream filePlanes;
    string line;
    vector<Plane> planesVector;

    filePlanes.open(directory + "Planes.txt");

    if (!filePlanes.is_open()) {
        throw runtime_error("File of Planes was not found");
    } else {
        while(getline(filePlanes, line)) {
            if (line.empty()) continue;
            vector<string> elements = split(line, ",");

            vector<queue<Service>> vServices = initializeServices(elements[0]);
            queue<Service> servicesCompleted = vServices[0];
            queue<Service> servicesToBeDone = vServices[1];
            vector<Flight> flightsVector = initializeFlights(elements[0]);

            Plane plane(elements[0], stoi(elements[1]), flightsVector, servicesCompleted, servicesToBeDone);
            planesVector.push_back(plane);
        }
    }

    filePlanes.close();
    return planesVector;
}

void Menu::pressAnyKeyToContinue() {
    cout << "Press enter to continue " << endl;
    cin.ignore(10000, '\n');
    getchar();
}

void Menu::printPlanes() {
    for (Plane plane : planes) {
        plane.print();
    }
}

void Menu::printFlights() {
    for (Plane plane : this->getPlanes()) {
        plane.printFlights();
    }
}

void Menu::printServices() {
    for (Plane plane : this->getPlanes()) {
        plane.printServices();
    }
}

void Menu::printAirports() {
    for (Airport airport : this->getAirports()) {
        airport.print();
    }
}

void Menu::printPassengers() {
    for (Passenger passenger : this->getPassengers()) {
        passenger.print();
    }
}

void Menu::printTickets() {
    for (Plane &plane : planes) {
        for (Flight &flight : plane.getFlightPlan()) {
            cout << "Tickets of flight number " << flight.getNumber() << endl;
            for (Ticket ticket : flight.getTickets()) {
                ticket.print();
            }
        }
    }
}

void Menu::printLocalTransports() {
    for (Airport airport : airports) {
        cout << "Local Transports of airport " << airport.getName() << endl;
        BSTItrIn it(airport.getBST());
        while (!it.isAtEnd()) {
            it.retrieve().print();
            it.advance();
        }
    }
}

void Menu::readPlanes() {
    int input; bool valid;
    cout << "\n1) Search a single plane" << endl;
    cout << "2) Search a set of planes" << endl;
    do {
        input = readInt();
        valid = input == 1 || input == 2;
        if (!valid) {
            cout << "Invalid Input. Try again." << endl;
        }
    } while (!valid);

    if (input == 1) {
        string lp;
        cout << "Please insert a license plate: ";
        lp = readString();
        if (this->getPlane(lp) != nullptr) {
            cout << "Plane found! " << endl;
            this->getPlane(lp)->print();
        } else {
            cout << "\nLicense plate not found" << endl;
        }

    } else {
        cout << "Ordered by: " << endl;
        cout << "1) License Plate" << endl;
        cout << "2) Capacity" << endl;
        cout << "3) Number of Flights" << endl;
        do {
            input = readInt();
            valid = (input == 1 || input == 2 || input == 3);
            if (!valid) {
                cout << "Invalid Input. Try again." << endl;
            }
        } while (!valid);

        if (input == 1) {
            sort(planes.begin() , planes.end() , Plane::compareByLicensePlate);
        } else  if (input == 2) {
            sort(planes.begin(), planes.end(), Plane::compareByCapacity);
        } else if (input == 3) {
            sort(planes.begin(), planes.end(), Plane::compareByNumberFlights);
        }
        printPlanes();
    }

}

void Menu::readFlights() {
    int input; bool valid;
    cout << "\n1) Search a single flight" << endl;
    cout << "2) Search a set of flights" << endl;
    cout << "3) See all flights" << endl;
    do {
        input = readInt();
        valid = (input == 1 || input == 2 || input == 3);
        if (!valid) {
            cout << "Invalid Input. Try again." << endl;
        }
    } while (!valid);

    if (input == 1) {
        int flightNumber;
        cout << "Please insert the Flight Number "; flightNumber = readInt();
        if (!isFlightNumberUnique(flightNumber)) {
            cout << "Flight found! " << endl;
            this->getFlight(flightNumber)->print();
        } else {
            cout << "\nFlight number not found" << endl;
        }

    } else if (input == 2 || input == 3) {
        int input2;
        cout << "Ordered by: " << endl;
        cout << "1) Number" << endl;
        cout << "2) Duration" << endl;
        cout << "3) Date" << endl;
        cout << "4) Number of Tickets" << endl;
        do {
            input2 = readInt();
            valid = input2 == 1 || input2 == 2 || input2 == 3 || input2 == 4;
            if (!valid) {
                cout << "Invalid Input. Try again." << endl;
            }
        } while (!valid);
        if (input == 3) {
            vector<Flight> allFlights = getAllFlights();
            if (input2 == 1) {
                sort(allFlights.begin() , allFlights.end() , Flight::compareByNumber);
            } else if (input2 == 2) {
                sort(allFlights.begin(), allFlights.end(), Flight::compareByDuration);
            } else if (input2 == 3) {
                sort(allFlights.begin(), allFlights.end(), Flight::compareByDate);
            } else {
                sort(allFlights.begin(), allFlights.end(), Flight::compareByNumberTickets);
            }
            for (Flight flight : allFlights) flight.print();
        } else if (input == 2) {
            string lp;
            cout << "Please insert a license plate: ";
            lp = readString();
            if (!isPlaneLpUnique(lp)) {
                cout << "Plane found! " << endl;
                if (input2 == 1) {
                    sort(this->getPlane(lp)->getFlightPlan().begin() , this->getPlane(lp)->getFlightPlan().end() , Flight::compareByNumber);
                } else if (input2 == 2) {
                    sort(this->getPlane(lp)->getFlightPlan().begin(), this->getPlane(lp)->getFlightPlan().end(), Flight::compareByDuration);
                } else if (input2 == 3) {
                    sort(this->getPlane(lp)->getFlightPlan().begin(), this->getPlane(lp)->getFlightPlan().end(), Flight::compareByDate);
                } else {
                    sort(this->getPlane(lp)->getFlightPlan().begin(), this->getPlane(lp)->getFlightPlan().end(), Flight::compareByNumberTickets);
                }
                this->getPlane(lp)->printFlights();
            } else {
                cout << "\nLicense plate not found" << endl;
            }
        }

    }
}

void Menu::readServices() {
    int input; bool valid;
    cout << "\n1) See next service required" << endl;
    cout << "2) See all services" << endl;
    do {
        input = readInt();
        valid = input == 1 || input == 2;
        if (!valid) {
            cout << "Invalid Input. Try again." << endl;
        }
    } while (!valid);

    if (input == 1) {
        string lp;
        cout << "Please insert the License Plate of the plane: "; lp = readString();
        if (this->getPlane(lp) != nullptr) {
            cout << "Service found! " << endl;
            this->getPlane(lp)->getServicesToBeDone().front().print(false);
        } else {
            cout << "\nFlight number not found" << endl;
        }
    } else {
        printServices();
    }
}

void Menu::readPassengers() {
    int input; bool valid;
    cout << "\n1) Search a single passenger" << endl;
    cout << "2) Search a set of passengers" << endl;
    do {
        input = readInt();
        valid = (input == 1 || input == 2);
        if (!valid) {
            cout << "Invalid Input. Try again." << endl;
        }
    } while (!valid);

    if (input == 1) {
        int idPassenger;
        cout << "Please insert the Passenger ID:  "; idPassenger = readInt();
        if (!this->isPassengerIdUnique(idPassenger)) {
            cout << "Passenger found! " << endl;
            this->getPassenger(idPassenger)->print();
        } else {
            cout << "\nPassenger ID not found" << endl;
        }

    } else {
        cout << "Ordered by: " << endl;
        cout << "1) Id" << endl;
        cout << "2) Name" << endl;
        cout << "3) Age" << endl;
        do {
            input = readInt();
            valid = (input == 1 || input == 2 || input == 3);
            if (!valid) {
                cout << "Invalid Input. Try again." << endl;
            }
        } while (!valid);
        if (input == 1) {
            sort(passengers.begin() , passengers.end() , Passenger::compareById);
        } else  if (input == 2) {
            sort(passengers.begin(), passengers.end(), Passenger::compareByName);
        } else if (input == 3) {
            sort(passengers.begin(), passengers.end(), Passenger::compareByAge);
        }
        printPassengers();
    }
}

void Menu::readAirports() {
    int input; bool valid;
    cout << "\n1) Search a single airport" << endl;
    cout << "2) Search a set of airports" << endl;
    do {
        input = readInt();
        valid = (input == 1 || input == 2);
        if (!valid) {
            cout << "Invalid Input. Try again." << endl;
        }
    } while (!valid);

    if (input == 1) {
        int idAirport;
        cout << "Please insert the Airport ID:  "; idAirport = readInt();
        if (!this->isAirportIdUnique(idAirport)) {
            cout << "Airport found! " << endl;
            this->getAirport(idAirport)->print();
        } else {
            cout << "\nAirport ID not found" << endl;
        }

    } else {
        cout << "Ordered by: " << endl;
        cout << "1) Id" << endl;
        cout << "2) Name" << endl;
        cout << "3) Number of Local Transports" << endl;
        do {
            input = readInt();
            valid = (input == 1 || input == 2 || input == 3);
            if (!valid) {
                cout << "Invalid Input. Try again." << endl;
            }
        } while (!valid);

        if (input == 1) {
            sort(airports.begin(), airports.end(), Airport::compareById);
        } else if (input == 2) {
            sort(airports.begin(), airports.end(), Airport::compareByName);
        } else {
            sort(airports.begin(), airports.end(), Airport::compareByNumberLocalTransports);
        }
        printPassengers();
    }
}

void Menu::readTickets() {
    int input, input2; bool valid;
    cout << "\n1) Search a set of tickets" << endl;
    cout << "2) See all tickets " << endl;
    do {
        input = readInt();
        valid = (input == 1 || input == 2);
        if (!valid) {
            cout << "Invalid Input. Try again." << endl;
        }
    } while (!valid);

    cout << "Ordered by: " << endl;
    cout << "1) Baggage" << endl;
    cout << "2) Price" << endl;
    cout << "3) Passenger Name" << endl;
    do {
        input2 = readInt();
        valid = (input2 == 1 || input2 == 2 || input2 == 3);
        if (!valid) {
            cout << "Invalid Input. Try again." << endl;
        }
    } while (!valid);

    if (input == 1) {
        int flightNumber;
        cout << "Please insert the Flight Number: "; flightNumber = readInt();
        if (!this->isFlightNumberUnique(flightNumber)) {
            cout << "Flight found! " << endl;
            Flight* flight = this->getFlight(flightNumber);
            if (input2 == 1) {
                sort(flight->getTickets().begin(), flight->getTickets().end(), Ticket::compareByBaggage);
            } else if (input2 == 2) {
                sort(flight->getTickets().begin(), flight->getTickets().end(), Ticket::compareByPrice);
            } else if (input2 == 3) {
                sort(flight->getTickets().begin(), flight->getTickets().end(), Ticket::compareByPassenger);
            }
            flight->printTickets();
        } else {
            cout << "\nFlight number not found" << endl;
        }

    } else {
        vector<Ticket> allTickets = getAllTickets();
        if (input2 == 1) {
            sort(allTickets.begin(), allTickets.end(), Ticket::compareByBaggage);
        } else if (input2 == 2) {
            sort(allTickets.begin(), allTickets.end(), Ticket::compareByPrice);
        } else if (input2 == 3) {
            sort(allTickets.begin(), allTickets.end(), Ticket::compareByPassenger);
        }
        for (Ticket ticket : allTickets) ticket.print();
    }

}

void Menu::readLocalTransports() {
    int input; bool valid;
    cout << "\n1) Search a set of Local Transports" << endl;
    cout << "2) See all Local Transports " << endl;
    do {
        input = readInt();
        valid = (input == 1 || input == 2);
        if (!valid) {
            cout << "Invalid Input. Try again." << endl;
        }
    } while (!valid);

    if (input == 1) {
        int idAirport;
        printAirports();
        cout << "Please insert the Airport ID: "; idAirport = readInt();
        if (!this->isAirportIdUnique(idAirport)) {
            cout << "Aiport Found! " << endl;
            getAirport(idAirport)->printLocalTransports();
        } else {
            cout << "\nAirport ID not found" << endl;
        }
    } else {
        printLocalTransports();
    }
}

bool Menu::buyTicket(int number, int baggage, int price, Passenger *passenger) {
    int capacity = getPlaneWithFlightNumber(number)->getCapacity();
    if (getFlight(number)->getTickets().size() < capacity) {
        Ticket ticket(baggage, price, passenger);
        getFlight(number)->getTickets().push_back(ticket);
        return true;
    }
    return false;
}

bool Menu::isPlaneLpUnique(string lp) {
    for (Plane plane : planes){
        if (plane.getLicensePlate() == lp) return false;
    }
    return true;
}

bool Menu::isFlightNumberUnique(int number){
    for (Plane plane : planes) {
        for (Flight flight : plane.getFlightPlan()) {
            if (flight.getNumber() == number) return false;
        }
    }
    return true;
}

bool Menu::isPassengerIdUnique(int id){
    for (Passenger passenger : passengers){
        if (passenger.getId() == id) return false;
    }
    return true;
}

bool Menu::isAirportIdUnique(int id) {
    for (Airport airport : airports) {
        if (airport.getId() == id) return false;
    }
    return true;
}

/*
1) Planes         2) Flights          3) Services             4) Airports
5) Tickets        6) Passengers       7) Local Transports     0) Back
 */
void Menu::create() {
    showClasses();
    //attributes
    int option = readInputClasses();
    if (option == 0) return;
    else if (option == 1) {
        string lp; int capacity; bool uniqueLp;
        do {
            cout << "Please insert a licence plate: " << endl;
            lp = readString();
            uniqueLp = true;
            if (!isPlaneLpUnique(lp)){
                cout << "Another plane already has this license plate!" << endl;
                uniqueLp = false;
            }
        } while (!uniqueLp);
        cout << "Please insert a capacity: " << endl;
        capacity = readInt();
        Plane plane(lp, capacity);
        planes.push_back(plane);
        cout << "You plane was successfully added." << endl;
    }
    else if (option == 2) {
        string lp, date; int number, originId, destinyId, duration;
        //criar number random? ou alguma logica?
        printPlanes();
        cout << "Please insert the airplane's licence plate: " << endl;
        lp = readString();
        printAirports();
        cout << "Please insert the ID of the Airport of departure: " << endl;
        originId = readInt();
        cout << "Please insert the ID of the Airport of destination: " << endl;
        destinyId = readInt();
        cout << "Please insert the number of the flight: " << endl;
        number = readInt();
        cout << "Please insert the duration of the flight: " << endl;
        duration = readInt();
        cout << "Please insert the date (DD-MM-YYYY): " << endl;
        date = readString();
        Flight flight(number, duration, getAirport(originId), getAirport(destinyId), date);
        this->getPlane(lp)->getFlightPlan().push_back(flight);
    }
    else if (option == 3) {
        printPlanes();
        string lp, typeOfService, date, worker;
        cout << "Please insert the airplane's licence plate: " << endl;
        lp = readString();
        cout << "Which is the type of the service: maintenance or cleaning?" << endl;
        typeOfService = readString();
        cout << "Please insert the date that the service will begin: " << endl;
        date = readString();
        cout << "What is the name of the worker doing this service?" << endl;
        worker = readString();
        Service service(typeOfService, date, worker);
        this->getPlane(lp)->getServicesToBeDone().push(service);
    }
    else if (option == 4) {
        string name; int id;
        cout << "Please insert the name of the airport: ";
        cin.ignore(1000, '\n');  // para conseguir ler um nome de aeroporto com mais do que uma palavra
        getline(cin, name);

        //falta depois ler os locais de transporte
        Airport airport((int) airports.size() + 1, name);
        airports.push_back(airport);
    }
    else if (option == 5) {
        int flightNumber, idPassenger, baggage, price;
        printFlights();
        cout << "Which flight is this for? Choose by flight number: " << endl;
        flightNumber = readInt();
        printPassengers();
        cout << "Who bought this ticket? Choose by ID: " << endl;
        idPassenger = readInt();
        //ainda temos de decidir como vamos representar bem a baggage
        cout << "Please insert the baggage: " << endl;
        baggage = readInt();
        cout << "Please insert the price: " << endl;
        price = readInt();

        if (buyTicket(flightNumber, baggage, price, getPassenger(idPassenger))) cout << "Ticket Successfully added" << endl;
        else cout << "I'm sorry, but this flight is already full" << endl;
    }
    else if (option == 6) {
        string name; int id, age; bool uniqueId;
        do {
            cout << "Please insert an ID for the passenger: " << endl;
            id = readInt();
            uniqueId = true;
            if (isPassengerIdUnique(id)){
                cout << "Another passenger already has this ID!" << endl;
                uniqueId = false;
            }
        } while (!uniqueId);
        cout << "Please insert the passenger's name: " << endl;
        name = readString();
        cout << "Please insert the passenger's age: " << endl;
        age = readInt();
        Passenger passenger(id, name, age);
        passengers.push_back(passenger);
    }
    else if (option == 7) {
        string typeTransport, times, date; int idAirport, distanceToAirport;
        printAirports();
        cout << "Please insert the closest airport's ID: "; idAirport = readInt();
        cout << "What is the type of transport: bus, train or subway? "; typeTransport = readString();
        cout << "Please insert the times you want for this transport: "; times = readString();
        cout << "Please insert the distance to the airport: "; distanceToAirport = readInt();
        LocalTransport localTransport(this->getAirport(idAirport)->getBSTSize()+1, typeTransport, times, distanceToAirport);
        this->getAirport(idAirport)->getBST().insert(localTransport);
    }
    pressAnyKeyToContinue();
}

/*
1) Planes         2) Flights          3) Services             4) Airports
5) Tickets        6) Passengers       7) Local Transports     0) Back
 */

void Menu::read() {
    showClasses();
    int option = readInputClasses();
    if (option == 0) return;
    else if (option == 1) readPlanes();
    else if (option == 2) readFlights();
    else if (option == 3) readServices();
    else if (option == 4) readAirports();
    else if (option == 5) readTickets();
    else if (option == 6) readPassengers();
    else if (option == 7) readLocalTransports();
}

void Menu::update() {
    showClasses();
    int option = readInputClasses();
    if (option == 0) return;
    else if (option == 1) {
        string lpId; int atributeToUpdate; bool appropriateInput;
        printPlanes();
        cout << "Insert the license plate of the plane you would like to update: " << endl;
        lpId = readString();
        do {
            appropriateInput = true;
            cout << "Which attribute would you like to update? "<< endl;
            cout << "1) License Plate"<< endl;
            cout << "2) Capacity"<< endl;
            atributeToUpdate = readInt();
            if (atributeToUpdate == 1){
                string newLp; bool uniqueLp;
                do {
                    cout << "What will the new license plate be? "<< endl;
                    newLp = readString();
                    uniqueLp = true;
                    if (!isPlaneLpUnique(newLp)){
                        cout << "Another plane already has this license plate!" << endl;
                        uniqueLp = false;
                    }
                } while (!uniqueLp);
                this->getPlane(lpId)->setLicensePlate(newLp);
            }
            else if (atributeToUpdate == 2){
                int newCapacity;
                cout << "What will the new capacity be? "<< endl;
                newCapacity = readInt();
                this->getPlane(lpId)->setCapacity(newCapacity);
            }
            else {
                cout << "Invalid number. Please try again." << endl;
                appropriateInput = false;
            }
        } while (!appropriateInput);
    }
    else if (option == 2) {
        int flightNumber, atributeToUpdate; bool appropriateInput;
        printFlights();
        do {
            cout << "Insert the flight number: "; flightNumber = readInt();
            if (!isFlightNumberUnique(flightNumber)) {
                appropriateInput = false;
            }
        } while (!appropriateInput);

        do {
            appropriateInput = true;
            cout << "Which attribute would you like to update? "<< endl;
            cout << "1) Flight Number"<< endl;
            cout << "2) Duration "<< endl;
            cout << "3) Airport of Departure" << endl;
            cout << "4) Airport of Arrival" << endl;
            atributeToUpdate = readInt();
            if (atributeToUpdate == 1){
                int newNumber; bool uniqueNumber;
                do {
                    cout << "What will the new number be? "<< endl;
                    newNumber = readInt();
                    uniqueNumber = true;
                    if (!isFlightNumberUnique(newNumber)){
                        cout << "Another plane already has this license plate!" << endl;
                        uniqueNumber = false;
                    }
                } while (uniqueNumber);
                this->getFlight(flightNumber)->setNumber(newNumber);
            }
            else if (atributeToUpdate == 2){
                int newDuration;
                cout << "What will the new duration of the flight be? "<< endl;
                newDuration = readInt();
                this->getFlight(flightNumber)->setDuration(newDuration);
            }
            else if (atributeToUpdate == 3 || atributeToUpdate == 4){
                int idAirport; bool uniqueAirport;
                printAirports();
                do {
                    uniqueAirport = true;
                    cout << "Insert the ID of the airport you would like to change to: " << endl;
                    idAirport = readInt();
                    if (isAirportIdUnique(idAirport)) {
                        if (atributeToUpdate == 3) {
                            this->getFlight(flightNumber)->setAirportOrigin(this->getAirport(idAirport));
                        } else {
                            this->getFlight(flightNumber)->setAirportDestiny(this->getAirport(idAirport));
                        }
                    } else {
                        uniqueAirport = false;
                    }
                } while (uniqueAirport);
            }
            else {
                cout << "Invalid number. Please try again." << endl;
                appropriateInput = false;
            }
        } while (!appropriateInput);
    }
    else if (option == 3) {
        string lp;
        printPlanes();
        cout << "Insert the license plate of the plane where the services are made: " << endl;
        lp = readString();
        bool appropriateInput;
        do {
            int atributeToUpdate;
            appropriateInput = true;
            cout << "Next ";
            this->getPlane(lp)->getServicesToBeDone().front().print(false);
            cout << "Would you like to check next service as completed? " << endl;
            cout << "1) Yes" << endl;
            cout << "2) No" << endl;
            atributeToUpdate = readInt();
            if (atributeToUpdate == 1) {
                this->getPlane(lp)->completeLastService();
            } else if (atributeToUpdate == 2) {
                break;
            } else {
                cout << "Invalid number. Please try again." << endl;
                appropriateInput = false;
            }
        } while (!appropriateInput);
    }
    else if (option == 4) {
        int idId, atributeToUpdate; bool appropriateInput;
        printAirports();
        cout << "Insert the ID of the airport you would like to update: " << endl;
        idId = readInt();
        string newName;
        cout << "What will the new name be? "<< endl;
        newName = readString();
        this->getAirport(idId)->setName(newName);
    }
    else if (option == 5) {
        int flightNumber, atributeToUpdate, ticketNumber; bool appropriateInput;
        printFlights();
        cout << "Insert the flight number of the ticket: " << endl;
        flightNumber = readInt();
        this->getFlight(flightNumber)->printTickets();
        cout << "What will the ticket id be? " << endl;
        ticketNumber = readInt();
        ticketNumber--;
        do {
            cout << "Which attribute would you like to update? "<< endl;
            cout << "1) Baggage"<< endl;
            cout << "2) Price"<< endl;
            cout << "3) Passenger"<< endl;
            atributeToUpdate = readInt();
            appropriateInput = true;
            if (atributeToUpdate == 1){
                int newBaggage;
                cout << "How much baggage will it be? "<< endl;
                newBaggage = readInt();
                this->getFlight(flightNumber)->getTickets()[ticketNumber-1].setBaggage(newBaggage);
            }
            else if (atributeToUpdate == 2){
                int newPrice;
                cout << "How much will it cost? "<< endl;
                newPrice = readInt();
                this->getFlight(flightNumber)->getTickets()[ticketNumber-1].setPrice(newPrice);
            }
            else if (atributeToUpdate == 3) {
                int idPassenger;
                printPassengers();
                cout << "Who will be the new Passenger? Id: "<< endl;
                idPassenger = readInt();
                this->getFlight(flightNumber)->getTickets()[ticketNumber-1].setPassenger(this->getPassenger(idPassenger));
            }
            else {
                cout << "Invalid number. Please try again." << endl;
                appropriateInput = false;
            }
        } while (!appropriateInput);
    }
    else if (option == 6) {
        int idId, atributeToUpdate; bool appropriateInput;
        printPassengers();
        cout << "Insert the ID of the passenger you would like to update: " << endl;
        idId = readInt();
        do{
            cout << "Which attribute would you like to update? "<< endl;
            cout << "1) ID"<< endl;
            cout << "2) Name"<< endl;
            cout << "3) Age"<< endl;
            atributeToUpdate = readInt();
            appropriateInput = true;
            if (atributeToUpdate == 1){
                int newId; bool uniqueId;
                do {
                    cout << "What will the new ID be? "<< endl;
                    newId = readInt();
                    uniqueId = true;
                    if (isPassengerIdUnique(newId)){
                        cout << "Another passenger already has this ID!" << endl;
                        uniqueId = false;
                    }
                } while (!uniqueId);
                this->getPassenger(idId)->setId(newId);
            }
            else if (atributeToUpdate == 2){
                string newName;
                cout << "What will the new name be? "<< endl;
                newName = readString();
                this->getPassenger(idId)->setName(newName);
            }
            else if (atributeToUpdate == 3){
                int newAge;
                cout << "What will the new age be? "<< endl;
                newAge = readInt();
                this->getPassenger(idId)->setAge(newAge);
            }
            else {
                cout << "Invalid number. Please try again." << endl;
                appropriateInput = false;
            }
        } while (!appropriateInput);
    }
    else if (option == 7) {
        int idAirport, idLT; bool notValid;
        printAirports();
        do {
            cout << "Insert the ID of the airport nearest to the Local Transports: "; idAirport = readInt(); cout << endl;
            notValid = this->isAirportIdUnique(idAirport);
            if (notValid) {
                cout << "Invalid Input" << endl;
            }
        } while (!notValid);

        this->getAirport(idAirport)->printLocalTransports();
        bool valid; string typeTransport, times; int distance;
        do {
            cout << "Which Local Transport would you like to update? ID: "; idLT = readInt();
            valid = this->getAirport(idAirport)->isLocalTransportId(idLT);
            if (!valid) {
                cout << "Invalid Input. Try Again" << endl;
            }
        } while (!valid);
        cout << "New Local Transport: " << endl;
        do {
            cout << "1) Type of Transport (bus, train or subway) : "; typeTransport = readString(); cout << endl;
            valid = typeTransport != "bus" || typeTransport != "train" || typeTransport != "subway";
            if (!valid) {
                cout << "Invalid Input" << endl;
                valid = false;
            }
        } while (!valid);
        cout << "2) Schedule: "; times = readString(); cout << endl;
        cout << "3) Distance to airport: "; distance = readInt(); cout << endl;
        LocalTransport lTRemove(idLT, "", "", 0);
        LocalTransport lTInsert(idLT, typeTransport, times, distance);
        this->getAirport(idAirport)->getBST().remove(lTRemove);
        this->getAirport(idAirport)->getBST().insert(lTInsert);

    } else {
        cout << "Invalid Input" << endl;
    }
}

void Menu::remove() {
    showClasses();
    int option = readInputClasses();
    if (option == 0) return;
    else if (option == 1) {
        string lp;
        printPlanes();
        cout << "What is the license plate of the plane you would like to delete?" << endl;
        lp = readString();
        for (int i = 0; i < planes.size(); i++){
            if (planes[i].getLicensePlate() == lp) {
                planes.erase(planes.begin() + i);
                break;
            }
        }
        cout << "Plane successfully deleted." << endl;
    }
    else if (option == 2) {
        int number; vector<Flight> fp;
        printFlights();
        cout << "What is the number of the flight you would like to delete?" << endl;
        number = readInt();
        fp = getPlaneWithFlightNumber(number)->getFlightPlan();
        for (int i = 0; i < fp.size(); i++){
            if (fp[i].getNumber() == number) {
                this->getPlaneWithFlightNumber(number)->getFlightPlan().erase(fp.begin() + i);
                break;
            }
        }
        cout << "Flight successfully deleted." << endl;
    }
    else if (option == 3) {
        string lp; int serviceToDelete; bool appropriateInput;
        printPlanes();
        cout << "What is the license plate of the plane with the service you want to delete?" << endl;
        lp = readString();
        do{
            appropriateInput = true;
            cout << "Which one do you want to delete?" << endl;
            cout << "1) The next service to be done. " << endl;
            cout << "2) The first service ever completed for this plane." << endl;
            serviceToDelete = readInt();
            if (serviceToDelete == 1){
                this->getPlane(lp)->getServicesToBeDone().pop();
                cout << "Service successfully deleted." << endl;
            }
            else if (serviceToDelete == 2){
                this->getPlane(lp)->getServicesCompleted().pop();
                cout << "Service successfully deleted." << endl;
            }
            else {
                cout << "Invalid number. Please try again." << endl;
                appropriateInput = false;
            }
        } while (!appropriateInput);
    }
    else if (option == 4) {
        int id;
        printAirports();
        cout << "What is the ID of the airport you would like to delete?" << endl;
        id = readInt();
        for (int i = 0; i < airports.size(); i++){
            if (airports[i].getId() == id) {
                airports.erase(airports.begin() + i);
                break;
            }
        }
        cout << "Airport successfully deleted." << endl;
    }
    else if (option == 5) {
        int flightNumber, ticketId;
        printFlights();
        cout << "What is the flight number of the ticket you want to delete?" << endl;
        flightNumber = readInt();
        this->getFlight(flightNumber)->printTickets();
        cout << "What is the ID of the ticket you want to delete?" << endl;
        ticketId = readInt(); ticketId--;
        this->getFlight(flightNumber)->getTickets().erase(this->getFlight(flightNumber)->getTickets().begin() + ticketId);
        cout << "Ticket successfully deleted." << endl;
    }
    else if (option == 6) {
        int id;
        printPassengers();
        cout << "What is the ID of the passenger you want to delete?" << endl;
        id = readInt();
        for (int i = 0; i < passengers.size(); i++){
            if (passengers[i].getId() == id) {
                passengers.erase(passengers.begin() + i);
                break;
            }
        }
        cout << "Passenger successfully deleted." << endl;
    }
    else if (option == 7) {
        int idAirport, idLT; bool notValid;
        printAirports();
        do {
            cout << "Insert the ID of the airport nearest to the Local Transports: "; idAirport = readInt(); cout << endl;
            notValid = this->isAirportIdUnique(idAirport);
            if (notValid) {
                cout << "Invalid Input" << endl;
            }
        } while (!notValid);
        this->getAirport(idAirport)->printLocalTransports();
        bool valid;
        do {
            cout << "Which Local Transport would you like to remove? ID: "; idLT = readInt();
            valid = this->getAirport(idAirport)->isLocalTransportId(idLT);
            if (!valid) {
                cout << "Invalid Input. Try Again" << endl;
            }
        } while (!valid);
        LocalTransport lTRemove(idLT, "", "", 0);
        this->getAirport(idAirport)->getBST().remove(lTRemove);
    }
}

void Menu::simulation(){
    int answerA, answerB, answerC, answerD, answerE, answerF, answerG; bool properInput;
    int id, idade; string nome;
    // part 1: creating/identifying a passenger
    do{
        properInput = false;
        cout << "\nHello, I'm Joana Pinto and welcome to the Airline Management Program!" << endl;
        cout << "Firstly, is this your first time being our customer?" << endl;
        cout << "1) It's my first time!" << endl;
        cout << "2) This ain't my first rodeo." << endl;
        cout << "3) I though this was a cheese store." << endl;
        answerA = readInt();
        if (answerA == 1 or answerA == 2 or answerA == 3) properInput = true;
    } while (!properInput);
    if (answerA == 1) {
        cout << "\nThen let me be the very first to welcome you to our Airline Management Program!" << endl;
        do{
            properInput = false;
            cout << "Can you give me your name?" << endl;
            cout << "1) You already welcomed me a second ago..." << endl;
            cout << "2) Sure thing!" << endl;
            answerB = readInt();
            if (answerB == 1 or answerB == 2) properInput = true;
        } while (!properInput);
        if (answerB == 1){
            cout << "Hey don't be rude! Get out!\n" << endl;
            cout << "\nThe End.\n" << endl;
        }
        else if (answerB == 2){
            cout  << "\nThen please write your name down here: " << endl;
            nome = readString();
            cout << nome << ", what a nice name!" << endl;
            do {
                properInput = false;
                cout << "Hmm.. by the look on your face..." << endl;
                cout << "I bet your age is the same as the number of times I've slipped on a banana peel!" << endl;
                cout << "It's..." << endl;
                idade = readInt(); //meio travado tenho de dar enter varias vezes
                if (idade >= 4 and idade <= 118) properInput = true;
                else if (idade > 118) {
                    cout << "Fun fact: the oldest person alive on Earth is currently 118 years old." << endl;
                    cout << "Thought you could fool me? Try again." << endl;
                } else if (idade < 4 ) {
                    cout << "I don't think someone below that age can even read. Try again." << endl;
                }
            } while(!properInput);
            cout << "Yes... " << idade << "... That is indeed the number of times I've slipped on a banana peel." << endl;
            cout << "I knew moving to a neighborhood of monkeys was a bad idea." << endl;
            do{
                properInput = false;
                cout << "Anyway, to finish your register, can you tell me your ID?" << endl;
                cout << "1) I have no IDea! (Badumtss)" << endl;
                cout << "2) Of course I can!" << endl;
                cout << "3) Woah! That is too personal! Why don't you tell me some of YOUR personal information first? Then we're even." << endl;
                answerC = readInt();
                if (answerC == 1 or answerC == 2) properInput = true;
                if (answerC == 3) {
                    cout << "If you say so..." << endl;
                    cout << "My name is Joana Pinto. I'm 42 years old." << endl;
                    cout << "My house is in the northeast section of Banana Town, where all the monkeys are, and I am not married." << endl;
                    cout << "I work as an employee for the Airline, and I get home every day by 8 PM at the latest." << endl;
                    cout << "I don't smoke, but I occasionally drink. " << endl;
                    cout << "I'm in bed by 11 PM, and make sure I get eight hours of sleep, no matter what." << endl;
                    cout << "After having a glass of warm milk and doing about twenty minutes of stretches before going to bed, I usually have no problems sleeping until morning." << endl;
                    cout << "Just like a baby, I wake up without any fatigue or stress in the morning. I was told there were no issues at my last check-up." << endl;
                    cout << "I'm trying to explain that I'm a person who wishes to live a very quiet life." << endl;
                    cout << "I take care not to trouble myself with any enemies, like winning and losing, that would cause me to lose sleep at night." << endl;
                    cout << "That is how I deal with society, and I know that is what brings me happiness. Although, if I were to fight I wouldn't lose to anyone." << endl;
                    cout << "\n(...)\n" << endl;
                    cout << "I feel like we should rewind this conversation a bit. Let's do that.\n" << endl;
                }
            }while (!properInput);
            if (answerC == 1) {
                cout << "That is a really bad joke... Please just get out." << endl;
                cout << "\nThe End.\n" << endl;
            }
            else if (answerC == 2){
                cout << "Very well!" << endl;
                do {
                    cout << "Please write your ID down here:" << endl;
                    id = readInt();
                    properInput = true;
                    if (!isPassengerIdUnique(id)) {
                        properInput = false;
                        cout << "I'm sorry, you must be mistaken. Someone else has that ID." << endl;
                        cout << "Let's try again." << endl;
                    }
                } while (!properInput);
                Passenger user (id, nome, idade);
                passengers.push_back(user);
                cout << "And just like that your register is complete." << endl;
                cout << "We hope this is the first of many times serving you, dear " << nome << "!" << endl;
            }
        }
    }
    else if (answerA == 2) {
        cout << "Then welcome back, dear customer!" << endl;
        do{
            properInput = false;
            cout << "Can you just give us your ID?" << endl;
            cout << "1) Only if you show me a funny monkey first!" << endl;
            cout << "2) For sure." << endl;
            answerB = readInt();
            if (answerB == 2) properInput = true;
            if (answerB == 1) {
                cout << "Fine, fine. You win. Here you go." << endl;
                cout << "          __" << endl;
                cout << "     w  c(..)o   (" << endl;
                cout << "      \\__(-)    __)" << endl;
                cout << "          /\\   (" << endl;
                cout << "         /(_)___)" << endl;
                cout << "         w /|" << endl;
                cout << "          | \\" << endl;
                cout << "         m  m" << endl;
                cout << "Now back to the task at hand." << endl;
            }
        } while (!properInput);
        if (answerB == 2){
            do{
                properInput = false;
                cout << "Write you ID down here:" << endl;
                id = readInt();
                for (Passenger passenger : passengers){
                    if (passenger.getId() == id) properInput = true;
                    }
                if (!properInput) {
                    cout << "I'm so sorry honey, but I'm not finding anyone on the database with that ID." << endl;
                    cout << "Don't worry, let's try again!" << endl;
                }
            } while (!properInput);
            cout << "Yes, right here... " << getPassenger(id)->getName() << "! It's a pleasure to serve you again!" << endl;
        }
    }
    else if (answerA == 3) {
        cout << "This is no place for cheese lovers! Get out!\n" << endl;
        cout << "\nThe End.\n" << endl;
    }
    //part 2: buying a ticket
    if ((answerA == 1 and answerB == 2 and answerC == 2) or (answerA == 2 and answerB == 2)) {
        int idDeparture, idDestination, flightNumber, baggage, price, priceSecond, priceTotal; bool properDeparture, properDestination;
        cout << "Alright, with the log in out of the way, let's talk about your flights!\n" << endl;
        do {
            properDeparture = false, properDestination = false;
            printAirports();
            cout << "\nHere are all the airports working with our airline!" << endl;
            cout << "Which one suits your departure better? Choose by ID." << endl;
            idDeparture = readInt();
            cout << "Ok, and what about the ID of your destination?" << endl;
            idDestination = readInt();
            for (Airport airport : airports) if (airport.getId() == idDeparture) properDeparture = true;
            for (Airport airport : airports) if (airport.getId() == idDestination) properDestination = true;
            if (idDestination == idDeparture) cout << "Oh no! It looks like you accidentally chose the same airport twice." << endl;
            if (!properDeparture) cout << "I'm sorry, the ID of the airport of departure you chose does not exist." << endl;
            if (!properDestination) cout << "I'm sorry, the ID of the airport of destination you chose does not exist." << endl;
            if ((idDeparture != idDeparture) and properDeparture and properDestination) properInput = true;
            if (!properInput) cout << "Please try again." << endl;
        } while (!properInput);
        cout << "Excellent choices! Believe me I could really use a vacation to somewhere near " << getAirport(idDestination)->getName() << "..." << endl;
        cout << "Now let me just show you the list of available flights." << endl;
        do {
            properInput = false;
            //print flights com os airports certos
            printFlights();
            cout << "Tell me the number of the flight you're interested in." << endl;
            flightNumber = readInt();
            //checka se ha vagas
            if (getPlaneWithFlightNumber(flightNumber)->getCapacity() > getFlight(flightNumber)->getTickets().size()) properInput = true;
            else cout << "We're sorry, that flight does not have any tickets available." << endl;
            if (!properInput) cout << "Try again." << endl;
        } while(!properInput);
        cout << "Yes, this one still has tickets available." << endl;
        do {
            properInput = false;
            cout << "Will you carry any baggage?" << endl;
            cout << "1) Not at all. My back hurts too much to carry stuff around." << endl;
            cout << "2) Just one bag." << endl;
            cout << "3) Multiple actually, a lot of stuff to take on my trip!" << endl;
            cout << "4) Do I count as baggage?" << endl;
            answerD = readInt();
            if (answerD == 1 or answerD == 2 or answerD == 3) properInput = true;
            if (answerD == 4) cout << "No.\n" << endl;
            if (!properInput and (answerD !=4)) cout << "Try again." << endl;
        } while(!properInput);
        if (answerD == 1){
            cout << "I get it. Back pains are the worst!" << endl;
            baggage = 0;
            price = getFlight(flightNumber)->getDuration()+10;
        }
        if (answerD == 2){
            cout << "Nice and simple. I like it!" << endl;
            baggage = 1;
            price = getFlight(flightNumber)->getDuration()+(42*baggage);
        }
        if (answerD == 3){
            cout << "Oh that is quite nice!" << endl;
            do {
                properInput = false;
                cout << "And how much baggage are we talking about?" << endl;
                baggage = readInt();
                if (baggage >= 2){
                    properInput = true;
                    price = getFlight(flightNumber)->getDuration()+(42*baggage);
                }
                if (!properInput) cout << "I dont think I would consider that 'multiple' baggage." << endl;
            } while (!properInput);
        }
        cout << "Then your ticket will be " << price << "$." << endl;
        do {
            properInput = false;
            cout << "Will that be ok?" << endl;
            cout << "1) Yeah, no problem." << endl;
            cout << "2) That much?! Nevermind, I'll just walk to my destination." << endl;
            answerE = readInt();
            if (answerE == 1 or answerE == 2) properInput = true;
            if (!properInput) cout << "Try again." << endl;
        }while(!properInput);
        if (answerE == 2) {
            cout << "Oh... Goodbye!" << endl;
            cout << "\nThe End.\n" << endl;
        }
        else if (getPlaneWithFlightNumber(flightNumber)->getCapacity() <= getFlight(flightNumber)->getTickets().size()+1){
            cout << "Got it! Then it will just be " << price << "$." << endl;
            cout << "(And so, you flew to " << getAirport(idDestination)->getName() << " and had an amazing trip!)" << endl;
            cout << "The End!\n" << endl;
        }
        else if (answerE == 1) {
            priceSecond = price / 2;
            cout << "Before you pay, I'd like to inform you we are having a special sale." << endl;
            cout << "You can buy a second ticket exactly like this one for only half the price!" << endl;
            cout << "That means it would only cost " << priceSecond << "$. Amazing, right?" << endl;
            do {
                properInput = false;
                cout << "1) That does seem pretty good. I'm in!" << endl;
                cout << "2) I'm fine with only one ticket, but thank you." << endl;
                answerF = readInt();
                if (answerF == 1 or answerF == 2) properInput = true;
                if (!properInput) cout << "Try again." << endl;
            }while (!properInput);
            Ticket ticket1 (baggage, price, getPassenger(id));
            getFlight(flightNumber)->getTickets().push_back(ticket1);
            if (answerF == 2) {
                cout << "Got it! Then it will just be " << price << "$." << endl;
                cout << "Thank you so much for choosing our airline! We hope to see you again!\n" << endl;
                cout << "(And so, you flew to " << getAirport(idDestination)->getName() << " and had an amazing trip!)" << endl;
                cout << "The End!\n" << endl;
            }
            else if (answerF == 1) {
                do{
                    Ticket ticket2 (baggage, priceSecond, getPassenger(id));
                    getFlight(flightNumber)->getTickets().push_back(ticket2);
                    priceTotal = price + priceSecond;
                    cout << "Got it! Then it will be " << priceTotal << "$ in total." << endl;
                    cout << "Two tickets, huh? Who will you take on your trip? Someone special? " << endl;
                    cout << "1) Just taking a friend. We're gonna have a blast!" << endl;
                    cout << "2) I was actually thinking of inviting you to go on vacation with me." << endl;
                    answerE = readInt();
                    if (answerE == 1 or answerE == 2) properInput = true;
                    if (!properInput) cout << "Try again." << endl;
                } while (!properInput);
                if (answerE == 1) {
                    cout << "(And so, you flew to " << getAirport(idDestination)->getName() << " with your friend and you indeed had a blast!)" << endl;
                    cout << "The End!\n" << endl;
                }
                else if (answerE == 2){
                    cout << "Oh. Really?! That is so sweet! I would love to go!" << endl;
                    cout << "(And so, you and Joana Pinto flew to " << getAirport(idDestination)->getName() << ", had a great vacation and became friends!)" << endl;
                    cout << "The End! <3\n" << endl;
                }
            }
        }
    }
}

void Menu::savePlanes() {
    ofstream filePlanes (directorySave + "Planes.txt");
    for (Plane plane : planes) {
        filePlanes << plane.getLicensePlate() << "," << plane.getCapacity() << endl;
    }
    filePlanes.close();
}

void Menu::saveAirports() {
    ofstream fileAirports (directorySave + "Airports.txt");
    for (Airport airport : airports) {
        fileAirports << airport.getId() << "," << airport.getName() << endl;
    }
    fileAirports.close();
}

void Menu::savePassengers() {
    ofstream filePassengers (directorySave + "Passengers.txt");
    for (Passenger passenger : passengers) {
        filePassengers << passenger.getId() << "," << passenger.getName() << "," << passenger.getAge() << endl;
    }
    filePassengers.close();
}

void Menu::saveFlights() {
    ofstream fileFlights (directorySave + "Flights.txt");
    for (Plane &plane : planes) {
        for (Flight &flight : plane.getFlightPlan()) {
            fileFlights << flight.getNumber() << "," << plane.getLicensePlate() << "," << flight.getOrigin()->getId() << "," <<
                        flight.getDestiny()->getId() << "," << flight.getDuration() << "," << flight.getDate().getStringDate() << endl;
        }
    }
    fileFlights.close();
}

void Menu::saveServices() {
    ofstream fileServices (directorySave + "Services.txt");
    for (Plane &plane : planes) {
        queue<Service> copyServicesToBeDone = plane.getServicesToBeDone();
        queue<Service> copyServicesCompleted = plane.getServicesCompleted();

        while (!copyServicesToBeDone.empty()) {
            Service service = copyServicesToBeDone.front();
            fileServices << plane.getLicensePlate() << "," << service.getTypeOfService() << "," << service.getDate().getStringDate() << "," << service.getWorker() << ",y" << endl;
            copyServicesToBeDone.pop();
        }

        while (!copyServicesCompleted.empty()) {
            Service service = copyServicesCompleted.front();
            fileServices << plane.getLicensePlate() << "," << service.getTypeOfService() << "," << service.getDate().getStringDate() << "," << service.getWorker() << ",n" << endl;
            copyServicesCompleted.pop();
        }
    }
    fileServices.close();
}

void Menu::saveTickets() {
    ofstream fileTickets (directorySave + "Tickets.txt");
    for (Plane &plane : planes) {
        for (Flight &flight : plane.getFlightPlan()) {
            for (Ticket ticket : flight.getTickets()) {
                fileTickets << flight.getNumber() << "," << ticket.getPassenger()->getId() << "," << ticket.getBaggage() << "," << ticket.getPrice() << endl;
            }
        }
    }
    fileTickets.close();
}

void Menu::saveLocalTransports() {
    ofstream fileLocalTransports (directorySave + "LocalTransports.txt");
    for (Airport &airport : airports) {
        BSTItrIn<LocalTransport> it(airport.getBST());
        while (!it.isAtEnd()) {
            LocalTransport lT = it.retrieve();
            fileLocalTransports << airport.getId() << "," << lT.getTypeTransport() << "," << lT.getStringTimes() << "," << lT.getDistanceToAirport() << endl;
            it.advance();
        }

    }
    fileLocalTransports.close();
}




/*
DOXYGEN NO FINAL!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! NÃO ESQUECER!!!!!!!!!!!!!!!
 Organizar o texto e tratar de "limpar" o screen
 * antonio trata
 outras cenas
 colocar times em Local Transports como listas

Simulation - Carrinho
Pesquisa


*/
