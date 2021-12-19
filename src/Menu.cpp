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
        //makes switch clauses
        //read();

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
    cout << "     0) Exit        " << endl;
}

void Menu::showClasses() {
    cout << "    1) Planes           " << endl;
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
    cin.ignore(10000, '\n');
    do {
        cin >> x;
        fail = cin.fail();
        if (fail)  {
            if (cin.eof()) {
                exit(0);
            }
            cin.clear();
            cin.ignore(10000, '\n');
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
            cin.ignore(10000, '\n');
            cout << "Invalid Input Try again: " << endl;
        }
    } while (fail);
    return str;
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


vector<Airport>& Menu::getAirports() {
    return airports;
}

vector<Passenger>& Menu::getPassengers() {
    return passengers;
}

vector<Plane>& Menu::getPlanes() {
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
            vector<string> elements = split(line);
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
            vector<string> elements = split(line);
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
            vector<string> elements = split(line);
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
            vector<string> elements = split(line);
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
            vector<string> elements = split(line);

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
            vector<string> elements = split(line);

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
    cout << "Press any key to continue " << endl;
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
        cin >> input;
        valid = input == 1 || input == 2;
        if (!valid) {
            cout << "Invalid Input. Try again." << endl;
        }
    } while (!valid);

    if (input == 1) {
        string lp;
        cout << "Please insert a license plate: "; cin >> lp;
        if (this->getPlane(lp) != nullptr) {
            cout << "Plane found! " << endl;
            this->getPlane(lp)->print();
        } else {
            cout << "\nLicense plate not found" << endl;
        }
    }

    if (input == 2) {
        cout << "Ordered by: " << endl;
        cout << "1) License Plate" << endl;
        cout << "2) Capacity" << endl;
        do {
            cin >> input;
            valid = input == 1 || input == 2;
            if (!valid) {
                cout << "Invalid Input. Try again." << endl;
            }
        } while (!valid);

        if (input == 1) {
            sort(this->getPlanes().begin() , this->getPlanes().end() , Plane::compareByLicensePlate);
        } else {
            sort(this->getPlanes().begin(), this->getPlanes().end(), Plane::compareByCapacity);
        }
        printPlanes();
    }

}

void Menu::readFlights() {
    int input; bool valid;
    cout << "\n1) Search a single flight" << endl;
    cout << "2) Search a set of flights" << endl;
    do {
        cin >> input;
        valid = input == 1 || input == 2;
        if (!valid) {
            cout << "Invalid Input. Try again." << endl;
        }
    } while (!valid);

    if (input == 1) {
        int flightNumber;
        cout << "Please insert the Flight Number "; cin >> flightNumber;
        if (this->getFlight(flightNumber) != nullptr) {
            cout << "Flight found! " << endl;
            this->getFlight(flightNumber)->print();
        } else {
            cout << "\nFlight number not found" << endl;
        }

    } else {


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
    //atributes
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
        Flight flight(number, duration, getAirport(originId), getAirport(destinyId), date);
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
            if (isPassengerIdUnique(id)){
                cout << "Another passenger already has this ID!" << endl;
                uniqueId = false;
            }
        } while (!uniqueId);
        cout << "Please insert the passenger's name: " << endl;
        cin >> name;
        cout << "Please insert the passenger's age: " << endl;
        cin >> age;
        Passenger passenger(id, name, age);
        passengers.push_back(passenger);
    }
    else if (option == 7) {
        string typeTransport, times, date; int idAirport, distanceToAirport;
        printAirports();
        cout << "Please insert the closest airport's ID: "; cin >> idAirport;
        cout << "What is the type of transport: bus, train or subway? "; cin >> typeTransport;
        cout << "Please insert the times you want for this transport: "; cin >> times;
        cout << "Please insert the distance to the airport: "; cin >> distanceToAirport;
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
    else if (option == 2) printFlights();
    else if (option == 3) printServices();
    else if (option == 4) printAirports();
    else if (option == 5) printTickets();
    else if (option == 6) printPassengers();
    else if (option == 7) printLocalTransports();
    pressAnyKeyToContinue();
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
        do {
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
        int flightNumber, atributeToUpdate; bool appropriateInput;
        printFlights();
        do {
            cout << "Insert the flight number: "; cin >> flightNumber;
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
            cin >> atributeToUpdate;
            if (atributeToUpdate == 1){
                int newNumber; bool uniqueNumber;
                do {
                    cout << "What will the new number be? "<< endl;
                    cin >> newNumber;
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
                cin >> newDuration;
                this->getFlight(flightNumber)->setDuration(newDuration);
            }
            else if (atributeToUpdate == 3 || atributeToUpdate == 4){
                int idAirport; bool uniqueAirport;
                printAirports();
                do {
                    uniqueAirport = true;
                    cout << "Insert the ID of the airport you would like to change to: " << endl;
                    cin >> idAirport;
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
        cin >> lp;
        bool appropriateInput;
        do {
            int atributeToUpdate;
            appropriateInput = true;
            cout << "Next ";
            this->getPlane(lp)->getServicesToBeDone().front().print(false);
            cout << "Would you like to check next service as completed? " << endl;
            cout << "1) Yes" << endl;
            cout << "2) No" << endl;
            cin >> atributeToUpdate;
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
        cin >> idId;
        string newName;
        cout << "What will the new name be? "<< endl;
        cin >> newName;
        this->getAirport(idId)->setName(newName);
    }
    else if (option == 5) {
        int flightNumber, atributeToUpdate, ticketNumber; bool appropriateInput;
        printFlights();
        cout << "Insert the flight number of the ticket: " << endl;
        cin >> flightNumber;
        this->getFlight(flightNumber)->printTickets();
        cout << "What will the ticket id be? " << endl;
        cin >> ticketNumber;
        ticketNumber--;
        do {
            cout << "Which attribute would you like to update? "<< endl;
            cout << "1) Baggage"<< endl;
            cout << "2) Price"<< endl;
            cout << "3) Passenger"<< endl;
            cin >> atributeToUpdate;
            appropriateInput = true;
            if (atributeToUpdate == 1){
                int newBaggage;
                cout << "How much baggage will it be? "<< endl;
                cin >> newBaggage;
                this->getFlight(flightNumber)->getTickets()[ticketNumber-1].setBaggage(newBaggage);
            }
            else if (atributeToUpdate == 2){
                int newPrice;
                cout << "How much will it cost? "<< endl;
                cin >> newPrice;
                this->getFlight(flightNumber)->getTickets()[ticketNumber-1].setPrice(newPrice);
            }
            else if (atributeToUpdate == 3) {
                int idPassenger;
                printPassengers();
                cout << "Who will be the new Passenger? Id: "<< endl;
                cin >> idPassenger;
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
            else if (atributeToUpdate == 3){
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
        int idAirport, idLT; bool notValid;
        printAirports();
        do {
            cout << "Insert the ID of the airport nearest to the Local Transports: "; cin >> idAirport; cout << endl;
            notValid = this->isAirportIdUnique(idAirport);
            if (notValid) {
                cout << "Invalid Input" << endl;
            }
        } while (!notValid);

        this->getAirport(idAirport)->printLocalTransports();
        bool valid; string typeTransport, times; int distance;
        do {
            cout << "Which Local Transport would you like to update? ID: "; cin >> idLT;
            valid = this->getAirport(idAirport)->isLocalTransportId(idLT);
            if (!valid) {
                cout << "Invalid Input. Try Again" << endl;
            }
        } while (!valid);
        cout << "New Local Transport: " << endl;
        do {
            cout << "1) Type of Transport (bus, train or subway) : "; cin >> typeTransport; cout << endl;
            valid = typeTransport != "bus" || typeTransport != "train" || typeTransport != "subway";
            if (!valid) {
                cout << "Invalid Input" << endl;
                valid = false;
            }
        } while (!valid);
        cout << "2) Schedule: "; cin >> times; cout << endl;
        cout << "3) Distance to airport: "; cin >> distance; cout << endl;
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
        cin >> lp;
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
        cin >> number;
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
        cin >> lp;
        do{
            appropriateInput = true;
            cout << "Which one do you want to delete?" << endl;
            cout << "1) The next service to be done. " << endl;
            cout << "2) The first service ever completed for this plane." << endl;
            cin >> serviceToDelete;
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
        cin >> id;
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
        cin >> flightNumber;
        this->getFlight(flightNumber)->printTickets();
        cout << "What is the ID of the ticket you want to delete?" << endl;
        cin >> ticketId; ticketId--;
        this->getFlight(flightNumber)->getTickets().erase(this->getFlight(flightNumber)->getTickets().begin() + ticketId);
        cout << "Ticket successfully deleted." << endl;
    }
    else if (option == 6) {
        int id;
        printPassengers();
        cout << "What is the ID of the passenger you want to delete?" << endl;
        cin >> id;
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
            cout << "Insert the ID of the airport nearest to the Local Transports: "; cin >> idAirport; cout << endl;
            notValid = this->isAirportIdUnique(idAirport);
            if (notValid) {
                cout << "Invalid Input" << endl;
            }
        } while (!notValid);
        this->getAirport(idAirport)->printLocalTransports();
        bool valid;
        do {
            cout << "Which Local Transport would you like to remove? ID: "; cin >> idLT;
            valid = this->getAirport(idAirport)->isLocalTransportId(idLT);
            if (!valid) {
                cout << "Invalid Input. Try Again" << endl;
            }
        } while (!valid);
        LocalTransport lTRemove(idLT, "", "", 0);
        this->getAirport(idAirport)->getBST().remove(lTRemove);
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
            flight.getDestiny()->getId() << "," << flight.getDuration() << "," << flight.getDate() << endl;
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
            fileServices << plane.getLicensePlate() << "," << service.getTypeOfService() << "," << service.getDate() << "," << service.getWorker() << ",y" << endl;
            copyServicesToBeDone.pop();
        }

        while (!copyServicesCompleted.empty()) {
            Service service = copyServicesCompleted.front();
            fileServices << plane.getLicensePlate() << "," << service.getTypeOfService() << "," << service.getDate() << "," << service.getWorker() << ",n" << endl;
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
            fileLocalTransports << airport.getId() << "," << lT.getTypeTransport() << "," << lT.getTimes() << "," << lT.getDistanceToAirport() << endl;
            it.advance();
        }

    }
    fileLocalTransports.close();
}





/*
DOXYGEN NO FINAL!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! NÃO ESQUECER!!!!!!!!!!!!!!!
 * antonio trata
Update  //Basico tratado
Remove  //Basico tratado
Date
 outras cenas
Testes
Simulation - Carrinho
Ordenação e pesquisa
Organizar o texto e tratar de "limpar" o screen

*/
