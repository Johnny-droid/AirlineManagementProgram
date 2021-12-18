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


vector<queue<Service>> Menu::initializeServices(string directory, string planeID) {
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
            vector<string> elements = split(line);
            if (elements[0] == planeID) {
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

            vector<queue<Service>> vServices = initializeServices(directory, elements[0]);
            queue<Service> servicesCompleted = vServices[0];
            queue<Service> servicesToBeDone = vServices[1];
            vector<Flight> flightsVector = initializeFlights(directory, elements[0]);

            Plane plane(elements[0], stoi(elements[1]), flightsVector, servicesCompleted, servicesToBeDone);
            planesVector.push_back(plane);
        }
    }

    filePlanes.close();
    return planesVector;
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
    for (Plane plane : planes) {
        for (Flight flight : plane.getFlightPlan()) {
            cout << "Tickets of flight number " << flight.getNumber() << endl;
            for (Ticket ticket : flight.getTickets()) {
                ticket.print();
            }
        }
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

bool Menu::isPlaneLpUnique(string lp){
    for (Plane plane : planes){
        if (plane.getLicensePlate() == lp) return false;
    }
    return true;
}

bool Menu::isAirportIdUnique(int id){
    for (Airport airport : airports){
        if (airport.getId() == id) return false;
    }
    return true;
}
bool Menu::isPassengerIdUnique(int id){
    for (Passenger passenger : passengers){
        if (passenger.getId() == id) return false;
    }
    return true;
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
        string lp; int capacity; bool uniqueLp;
        do {
            cout << "Please insert a licence plate: " << endl;
            cin >> lp;
            uniqueLp = true;
            if (isPlaneLpUnique(lp)){
                cout << "Another plane already has this license plate!" << endl;
                uniqueLp = false;
            }
        } while (!uniqueLp);
        cout << "Please insert a capacity: " << endl;
        cin >> capacity;
        Plane plane(lp, capacity);
        planes.push_back(plane);
        cout << "You plane was successfully added." << endl;
    }
    else if (option == 2) {
        string lp, date; int number, originId, destinyId, duration;
        //criar number random? ou alguma logica?
        printPlanes();
        cout << "Please insert the airplane's licence plate: " << endl;
        cin >> lp;
        printAirports();
        cout << "Please insert the ID of the Airport of departure: " << endl;
        cin >> originId;
        cout << "Please insert the ID of the Airport of destination: " << endl;
        cin >> destinyId;
        cout << "Please insert the number of the flight: " << endl;
        cin >> number;
        cout << "Please insert the duration of the flight: " << endl;
        cin >> duration;
        cout << "Please insert the date (DD-MM-YYYY): " << endl;
        cin >> date;
        Flight flight(number, duration, getAirport(originId), getAirport(destinyId));
        this->getPlane(lp)->getFlightPlan().push_back(flight);
    }
    else if (option == 3) {
        printPlanes();
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
        this->getPlane(lp)->getServicesToBeDone().push(service);
    }
    else if (option == 4) {
        string name; int id; bool uniqueId;
        do {
            cout << "Please insert an ID for the airport: " << endl;
            cin >> id;
            uniqueId = true;
            if (isAirportIdUnique(id)){
                cout << "Another airport already has this ID!" << endl;
                uniqueId = false;
            }
        } while (!uniqueId);
        cout << "Please insert the name of the airport: ";
        cin.ignore(1000, '\n');  // para conseguir ler um nome de aeroporto com mais do que uma palavra
        getline(cin, name);

        //falta depois ler os locais de transporte
        Airport airport((int id) airports.size(), name);
        airports.push_back(airport);
    }
    else if (option == 5) {
        int flightNumber, idPassenger, baggage, price;
        printFlights();
        cout << "Which flight is this for? Choose by flight number: " << endl;
        cin >> flightNumber;
        printPassengers();
        cout << "Who bought this ticket? Choose by ID: " << endl;
        cin >> idPassenger;
        //ainda temos de decidir como vamos representar bem a baggage
        cout << "Please insert the baggage: " << endl;
        cin >> baggage;
        cout << "Please insert the price: " << endl;
        cin >> price;

        if (buyTicket(flightNumber, baggage, price, getPassenger(idPassenger))) cout << "Ticket Successfully added" << endl;
        else cout << "I'm sorry, but this flight is already full" << endl;
    }
    else if (option == 6) {
        string name; int id, age; bool uniqueId;
        do {
            cout << "Please insert an ID for the passenger: " << endl;
            cin >> id;
            uniqueId = true;
            if (isAirportIdUnique(id)){
                cout << "Another passenger already has this ID!" << endl;
                uniqueId = false;
            }
        } while (!uniqueId);
        cout << "Please insert the passenger's name: " << endl;
        cin >> name;
        cout << "Please insert the passenger's age: " << endl;
        cin >> age;
        Passenger passenger(passengers.size(), name, age);
        passengers.push_back(passenger);
    }
    else if (option == 7) {
        string typeTransport, times, date; int idAirport, distanceToAirport;
        printAirports();
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
}

/*
1) Planes         2) Flights          3) Services             4) Airports
5) Tickets        6) Passengers       7) Local Transports     0) Back
 */

void Menu::read() {
    showClasses();
    int option = readInputClasses();
    if (option == 0) return;
    else if (option == 1) printPlanes();
    else if (option == 2) printFlights();
    else if (option == 3) printServices();
    else if (option == 4) printAirports();
    else if (option == 5) printTickets();
    else if (option == 6) printPassengers();
    else if (option == 7) {
        //print Local transports
    }

}

void Menu::update() {
    showClasses();
    int option = readInputClasses();
    if (option == 0) return;
    else if (option == 1) {
        string lpId; int atributeToUpdate; bool appropriateInput;
        printPlanes();
        cout << "Insert the license plate of the plane you would like to update: " << endl;
        cin >> lpId;
        do{
            appropriateInput = true;
            cout << "Which attribute would you like to update? "<< endl;
            cout << "1) License Plate"<< endl;
            cout << "2) Capacity"<< endl;
            cin >> atributeToUpdate;
            if (atributeToUpdate == 1){
                string newLp; bool uniqueLp;
                do {
                    cout << "What will the new license plate be? "<< endl;
                    cin >> newLp;
                    uniqueLp = true;
                    if (isPlaneLpUnique(newLp)){
                        cout << "Another plane already has this license plate!" << endl;
                        uniqueLp = false;
                    }
                } while (!uniqueLp);
                this->getPlane(lpId)->setLicensePlate(newLp);
            }
            else if (atributeToUpdate == 2){
                int newCapacity;
                cout << "What will the new capacity be? "<< endl;
                cin >> newCapacity;
                this->getPlane(lpId)->setCapacity(newCapacity);
            }
            else {
                cout << "Invalid number. Please try again." << endl;
                appropriateInput = false;
            }
        } while (!appropriateInput);
    }
    else if (option == 2) {
        //por fazer
    }
    else if (option == 3) {
        //por fazer
    }
    else if (option == 4) {
        int idId, atributeToUpdate; bool appropriateInput;
        printAirports();
        cout << "Insert the ID of the airport you would like to update: " << endl;
        cin >> idId;
        do{
            cout << "Which attribute would you like to update? "<< endl;
            cout << "1) ID"<< endl;
            cout << "2) Name"<< endl;
            cin >> atributeToUpdate;
            appropriateInput = true;
            if (atributeToUpdate == 1){
                int newId; bool uniqueId;
                do {
                    cout << "What will the new ID be? "<< endl;
                    cin >> newId;
                    uniqueId = true;
                    if (isAirportIdUnique(newId)){
                        cout << "Another airport already has this ID!" << endl;
                        uniqueId = false;
                    }
                } while (!uniqueId);
                this->getAirport(idId)->setId(newId);
            }
            else if (atributeToUpdate == 2){
                string newName;
                cout << "What will the new name be? "<< endl;
                cin >> newName;
                this->getAirport(idId)->setName(newName);
            }
            else {
                cout << "Invalid number. Please try again." << endl;
                appropriateInput = false;
            }
        } while (!appropriateInput);
    }
    else if (option == 5) {
        //por fazer
    }
    else if (option == 6) {
        int idId, atributeToUpdate; bool appropriateInput;
        printPassengers();
        cout << "Insert the ID of the passenger you would like to update: " << endl;
        cin >> idId;
        do{
            cout << "Which attribute would you like to update? "<< endl;
            cout << "1) ID"<< endl;
            cout << "2) Name"<< endl;
            cout << "3) Age"<< endl;
            cin >> atributeToUpdate;
            appropriateInput = true;
            if (atributeToUpdate == 1){
                int newId; bool uniqueId;
                do {
                    cout << "What will the new ID be? "<< endl;
                    cin >> newId;
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
                cin >> newName;
                this->getPassenger(idId)->setName(newName);
            }
            else if (atributeToUpdate == 2){
                int newAge;
                cout << "What will the new age be? "<< endl;
                cin >> newAge;
                this->getPassenger(idId)->setAge(newAge);
            }
            else {
                cout << "Invalid number. Please try again." << endl;
                appropriateInput = false;
            }
        } while (!appropriateInput);
    }
    else if (option == 7) {
        //por fazer
    }
}

void Menu::remove() {
    showClasses();
    int option = readInputClasses();
}

/*
 * antonio trata
Update
Remove
Date
 outras cenas
Local Transports
Simulation - Carrinho
Ordenação e pesquisa
 Organizar o texto
*/

