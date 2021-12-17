#include "Menu.h"



using namespace std;

Menu::Menu(string directory) {
    this->airports = initializeAirports(directory);
    this->passengers = initializePassengers(directory);
    this->planes = initializePlanes(directory);
}

void Menu::run(string directory) {
    int option;
    Menu menu(directory);
    do {
        showMenu();
        option = readInputMenu();
        if (option == 1) menu.create();
        if (option == 2) menu.read();
        if (option == 3) menu.update();
        if (option == 4) menu.remove();
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

void Menu::showClasses() {
    cout << "     1) Planes          " << endl;
    cout << "     2) Flights         " << endl;
    cout << "     3) Services        " << endl;
    cout << "     4) Airports        " << endl;
    cout << "     5) Tickets         " << endl;
    cout << "     6) Passengers      " << endl;
    cout << "     0) Back            " << endl;
}


int Menu::readInputMenu() {
    // gets the option number
    int chosenOption;
    bool notValid;
    do {
        cout << "\n     Enter option: ";
        cin >> chosenOption;
        notValid = chosenOption != 1 && chosenOption != 2 && chosenOption != 3 && chosenOption != 4 && chosenOption != 5 && chosenOption != 6 && chosenOption != 0 ;
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
        notValid = chosenOption != 1 && chosenOption != 2 && chosenOption != 3 && chosenOption != 4 && chosenOption != 0;
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

vector<string> Menu::split(string s) {
    vector<string> v;

    while (s.length() != 0) {
        int pos = s.find_first_of(",");
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


vector<Airport> Menu::getAirports() {
    return airports;
}

vector<Passenger> Menu::getPassengers() {
    return passengers;
}

vector<Plane> Menu::getPlanes() {
    return planes;
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

Flight *Menu::getFlight(int number, string directory, string licensePlate) {
    for (Flight &flight : initializeFlights(directory, licensePlate)) {
        if (flight.getNumber() == number) {
            Flight* flightPtr = &flight;
            return flightPtr;
        }
    }
    return nullptr;
}

vector<Airport> Menu::initializeAirports(string directory) {
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
            vector<string> elements = split(line);
            Airport airport(stoi(elements[0]), elements[1]);
            airportsVector.push_back(airport);
        }
    }

    fileAirport.close();
    return airportsVector;
}

vector<Passenger> Menu::initializePassengers(string directory) {
    ifstream filePassengers;
    string line;
    vector<Passenger> passengersVector;

    filePassengers.open(directory + "Passengers.txt");

    if (!filePassengers.is_open()) {
        throw runtime_error("File of Passengers was not found");
    } else {
        while(getline(filePassengers, line)) {
            if (line.empty()) continue;
            vector<string> elements = split(line);
            Passenger passenger(stoi(elements[0]), elements[1], stoi(elements[2]));
            passengersVector.push_back(passenger);
        }
    }

    filePassengers.close();

    return passengersVector;
}


queue<Service> Menu::initializeServices(string directory, string planeID) {
    ifstream fileServices;
    string line;
    queue<Service> servicesQueue;

    fileServices.open(directory + "Services.txt");

    if (!fileServices.is_open()) {
        throw runtime_error("File of Services was not found");
    } else {
        while(getline(fileServices, line)) {
            if (line.empty()) continue;
            vector<string> elements = split(line);
            if (elements[0] == planeID) {
                Service service(elements[1], elements[2], elements[3]);
                servicesQueue.push(service);
            }
        }
    }

    fileServices.close();

    return servicesQueue;
}

vector<Ticket> Menu::initializeTickets(string directory, int flightID) {
    ifstream fileTickets;
    string line;
    vector<Ticket> ticketsVector;

    fileTickets.open(directory + "Tickets.txt");

    if (!fileTickets.is_open()) {
        throw runtime_error("File of Tickets was not found");
    } else {
        while(getline(fileTickets, line)) {
            if (line.empty()) continue;
            vector<string> elements = split(line);

            if (stoi(elements[0]) == flightID) {
                Ticket ticket( stoi(elements[2]) , stoi(elements[3]), this->getPassenger(stoi(elements[1])));
                ticketsVector.push_back(ticket);
            }
        }
    }

    fileTickets.close();
    return ticketsVector;
}

vector<Flight> Menu::initializeFlights(string directory, string planeLicensePlate) {
    ifstream fileFlights;
    string line;
    vector<Flight> flightsVector;

    fileFlights.open(directory + "Flights.txt");

    if (!fileFlights.is_open()) {
        throw runtime_error("File of Flights was not found");
    } else {
        while(getline(fileFlights, line)) {
            if (line.empty()) continue;
            vector<string> elements = split(line);

            if (elements[1] == planeLicensePlate) {
                Airport* origin = this->getAirport(stoi(elements[2]));
                Airport* destiny = this->getAirport(stoi(elements[3]));
                vector<Ticket> tickets = initializeTickets(directory, stoi(elements[0]));
                Flight flight(stoi(elements[0]), stoi(elements[4]), origin, destiny, tickets);
                flightsVector.push_back(flight);
            }
        }
    }

    fileFlights.close();

    return flightsVector;
}

vector<Plane> Menu::initializePlanes(string directory) {
    ifstream filePlanes;
    string line;
    vector<Plane> planesVector;

    filePlanes.open(directory + "Planes.txt");

    if (!filePlanes.is_open()) {
        throw runtime_error("File of Planes was not found");
    } else {
        while(getline(filePlanes, line)) {
            if (line.empty()) continue;
            vector<string> elements = split(line);

            queue<Service> servicesQueue = initializeServices(directory, elements[0]);
            vector<Flight> flightsVector = initializeFlights(directory, elements[0]);

            Plane plane(elements[0], stoi(elements[1]), flightsVector, servicesQueue);
            planesVector.push_back(plane);
        }
    }

    filePlanes.close();
    return planesVector;
}

void Menu::printPlanes() {
    for (int i = 0; i < this->getPlanes().size(); i++) {
        cout << "Plane " << i << "   License Plate: " << this->getPlanes()[i].getLicensePlate() << "    Capacity: "
             << this->getPlanes()[i].getCapacity() << endl;
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
        cout << "Airport " << airport.getId() << ": " << airport.getName() << endl;
    }
}

void Menu::printPassengers() {
    for (Passenger passenger : this->getPassengers()) {
        cout << "Passenger ID: " << passenger.getId() << "   Name: " << passenger.getName() << "   Age: " << passenger.getAge() << endl;
    }
}

/*
1) Planes         2) Flights          3) Services             4) Airports
5) Tickets        6) Passengers       7) Local Transports     0) Back
 */
void Menu::create() {
    showClasses();
    //atributes
    int option = readInputClasses();
    if (option == 0) return;
    else if (option == 1) {
        string lp; int capacity; vector<Flight> flights; queue<Service> services;
        cout << "Please insert a licence plate: " << endl;
        cin >> lp;
        cout << "Please insert a capacity: " << endl;
        cin >> capacity;
        Plane plane(lp, capacity, flights, services);
    }
    else if (option == 2) {
        string lp, date; int number, originId, destinyId, duration; vector<Ticket> tickets;
        //criar number random? ou alguma logica?
        printPlanes();
        cout << "Please insert the airplane's licence plate: " << endl;
        cin >> lp;
        printAirports();
        cout << "Please insert the ID of the Airport of departure: " << endl;
        cin >> originId;
        cout << "Please insert the ID of the Airport of destination: " << endl;
        cin >> destinyId;
        cout << "Please insert the duration of the flight: " << endl;
        cin >> duration;
        cout << "Please insert the date (DD-MM-YYYY): " << endl;
        cin >> date;
        Flight flight(number, duration, getAirport(originId), getAirport(destinyId), tickets);
        getPlane(lp)->getFlightPlan().push_back(flight);
    }
    else if (option == 3) {
        //print airplanes
        string lp, typeOfService, date, worker;
        cout << "Please insert the airplane's licence plate: " << endl;
        cin >> lp;
        cout << "Which is the type of the service: maintenance or cleaning?" << endl;
        cin >> typeOfService;
        cout << "Please insert the date that the service will begin: " << endl;
        cin >> date;
        cout << "What is the name of the worker doing this service?" << endl;
        cin >> worker;
        Service service(typeOfService, date, worker);
        /* precisa de dar para comparar datas
        if (date > dateHoje) {
            getPlane(lp)->getServicesToBeDone().push(service);
        } else getPlane(lp)->getServicesCompleted().push(service); */
    }
    else if (option == 4) {
        string name; int id;
        //criar id random ou a pessoa escreve ou como?
        cout << "Please insert the name of the airport: " << endl;
        cin >> name;
        Airport airport(id, name);

    }
    else if (option == 5) {
        int idFlight, idPassenger, baggage, price;
        //print flights
        cout << "Which flight is this for? Choose by ID: " << endl;
        cin >> idFlight;
        //print passengers
        cout << "Who bought this ticket? Choose by ID: " << endl;
            cin >> idPassenger;
        //ainda temos de decidir como vamos representar bem a baggage
        cout << "Please insert the baggage: " << endl;
        cin >> baggage;
        cout << "Please insert the price: " << endl;
        cin >> price;
        Ticket ticket(baggage, price, getPassenger(idPassenger));
        string directory, lp; // é preciso ir busca los algures
        getFlight(idFlight, directory, lp)->getTickets().push_back(ticket);
    }
    else if (option == 6) {
        string name; int id, age;
        //criar id random? ou alguma logica?
        cout << "Please insert the passenger's name: " << endl;
        cin >> name;
        cout << "Please insert the passenger's age: " << endl;
        cin >> age;
        Passenger passenger(id, name, age);
    }
    else if (option == 7) {
        string typeTransport, times, date; int idAirport, distanceToAirport;
        //print airports
        cout << "Please insert the closest airport's ID: " << endl;
        cin >> idAirport;
        cout << "What is the type of transport: bus, train or subway? " << endl;
        cin >> typeTransport;
        cout << "Please insert the date you want this transport: " << endl;
        cin >> date;
        cout << "Please insert the distance to the airport: " << endl;
        cin >> distanceToAirport;
        //arranjar o times
        LocalTransport localTransport(typeTransport, times, distanceToAirport);
        //adicionar à arvore binaria de getAirport(idAirport)
    }
    /* caso tenha feito asneira
    string lp, date,service, worker, name, transportType;
    int capacity, departure, destination, duration, idAirport, idFlight, idTicket, baggage, price, age, distance;
    switch (option) {
        case 1:
            cout << "Please insert a licence plate: " << endl;
            cin >> lp;
            cout << "Please insert a capacity: " << endl;
            cin >> capacity;
            break;
        case 2:
            //criar id random
            printPlanes();
            cout << "Please insert the airplane's licence plate: " << endl;
            cin >> lp;
            printAirports();
            cout << "Please insert the ID of the Airport of departure: " << endl;
            cin >> departure;
            cout << "Please insert the ID of the Airport of destination: " << endl;
            cin >> destination;
            cout << "Please insert the duration of the flight: " << endl;
            cin >> duration;
            cout << "Please insert the date (DD-MM-YYYY): " << endl;
            cin >> date;
            break;
        case 3:
            printPlanes();
            cout << "Please insert the airplane's licence plate: " << endl;
            cin >> lp;
            cout << "Which is the type of the service: maintenance or cleaning?" << endl;
            cin >> service;
            cout << "Please insert the date that the service will begin: " << endl;
            cin >> date;
            cout << "What is the name of the worker doing this service?" << endl;
            cin >> worker;
            break;
        case 4:
            //criar id random
            cout << "Please insert the name of the airport: " << endl;
            cin >> name;
            break;
        case 5:
            printFlights();
            cout << "Which flight is this for? Choose by ID: " << endl;
            cin >> idFlight;
            printPassengers();
            cout << "Who bought this ticket? Choose by ID: " << endl;
            cin >> idTicket;
            cout << "Please insert the baggage: " << endl;
            cin >> baggage;
            cout << "Please insert the price: " << endl;
            cin >> price;
            break;
        case 6:
            //criar id random
            cout << "Please insert the passenger's name: " << endl;
            cin >> name;
            cout << "Please insert the passenger's age: " << endl;
            cin >> age;
            break;
        case 7:
            cout << "Please insert the ID of the Airport: " << endl;
            cin >> idAirport;
            cout << "Please insert the airplane's licence plate: " << endl;
            cin >> lp;
            cout << "What is the type of transport: bus, train or subway? " << endl;
            cin >> transportType;
            cout << "Please insert the date you want this transport: " << endl;
            cin >> date;
            cout << "Please insert the distance to the airport: " << endl;
            cin >> distance;
            break;
        default:
            break;
    }
     */
}

void Menu::read() {
    showClasses();
    int option = readInputClasses();
    switch (option) {
        case 1:
            break;
        case 2:
            cout << "" << endl;
            break;
    }

}

void Menu::update() {
    showClasses();
    int option = readInputClasses();
    //atribute
    string lp, date,service, worker, name;
    int capacity, departure, destination, duration;
}

void Menu::remove() {
    showClasses();
    int option = readInputClasses();
}



