#include <vector>
#include "Flight.h"

/**
 * Create a flight object with an empty ticket list and the default values for stackMax, carriageMaxSize and cartMaxSize
 * @param number The flight's ID number
 * @param duration The flight's duration
 * @param origin The airport object from which the journey starts
 * @param destiny The airport object from which the journey ends
 * @param date The string that represents a date in the model 'DD-MM-YYYY' that will be turned into a date object
 */

Flight::Flight(int number, int duration, Airport *origin, Airport *destiny, string date) {
    Date date1(date);
    this->dateDeparture = date1;
    this->number = number;
    this->duration = duration;
    this->origin = origin;
    this->destiny = destiny;
    this->tickets = vector<Ticket>();
    this->stackMax = 10;
    this->carriageMaxSize = 4;
    this->cartMaxSize = 3;
}

/**
 * Create a flight object with an default ticket list and default values for stackMax, carriageMaxSize and cartMaxSize
 * @param number The flight's ID number
 * @param duration The flight's duration
 * @param origin The airport object from which the journey starts
 * @param destiny The airport object from which the journey ends
 * @param date The string that represents a date in the model 'DD-MM-YYYY' that will be turned into a date object
 * @param tickets A vector where all of the flight's ticket objects are stored
 */

Flight::Flight(int number, int duration, Airport *origin, Airport *destiny, string date, vector<Ticket> tickets) {
    Date date1(date);
    this->dateDeparture = date1;
    this->number = number;
    this->duration = duration;
    this->origin = origin;
    this->destiny = destiny;
    this->tickets = tickets;
    this->stackMax = 10;
    this->carriageMaxSize = 4;
    this->cartMaxSize = 3;
}
/**
 * Create a flight object with an default ticket list and the default values for stackMax, carriageMaxSize and cartMaxSize
 * @param number The flight's ID number
 * @param duration The flight's duration
 * @param origin The airport object from which the journey starts
 * @param destiny The airport object from which the journey ends
 * @param date The string that represents a date in the model 'DD-MM-YYYY' that will be turned into a date object
 * @param tickets A vector where all of the flight's ticket objects are stored
 * @param stackMax The maximum amount of baggage that can go into a stack
 * @param carriageMaxSize The maximum number of stacks a carriage can have
 * @param cartMaxSize The maximum number of carriages a cart can have
 */
Flight::Flight(int number, int duration, Airport *origin, Airport *destiny, string date, vector<Ticket> tickets, int stackMax, int carriageMaxSize, int cartMaxSize) {
    Date date1(date);
    this->dateDeparture = date1;
    this->number = number;
    this->duration = duration;
    this->origin = origin;
    this->destiny = destiny;
    this->tickets = tickets;
    this->stackMax = stackMax;
    this->carriageMaxSize = carriageMaxSize;
    this->cartMaxSize = cartMaxSize;
}
//vector<vector<vector<stack<int>>>> Flight::baggageCarts = buildCarts(stackMax, carriageMaxSize, cartMaxSize);

/**
 * Organizes the baggages into a system. Every baggage is put on a stack, every stack is put on a carriage, every carriage belongs to a cart, and every cart is part of the vector of all carts for that flight
 * @param stackMax The maximum amount of baggage that can go into a stack
 * @param carriageMaxSize The maximum number of stacks a carriage can have
 * @param cartMaxSize The maximum number of carriages a cart can have
 * @return A Vector with every cart
 */
vector<vector<vector<stack<int>>>> Flight::buildCarts() {
    stack<int> stac; int amountOnStack = 0; int amountBaggage;
    vector<stack<int>> carriage {}; vector<vector<stack<int>>> cart {}; vector<vector<vector<stack<int>>>> allCarts {};
    for (Ticket ticket : tickets) {
        amountBaggage = ticket.getBaggage();
        if ((amountBaggage + amountOnStack) <= stackMax){
            amountOnStack += amountBaggage;
            stac.push(ticket.getBaggage());
        }
        else {
            stack<int> stacCopy;
            carriage.push_back(stacCopy);
            stac = {};
            amountOnStack = amountBaggage;
            stac.push(ticket.getBaggage());
            if (carriage.size() == carriageMaxSize) {
                vector<stack<int>> carriageCopy = carriage;
                carriage = {};
                if (cart.size() < cartMaxSize){
                    cart.push_back(carriageCopy);
                }
                else {
                    vector<vector<stack<int>>> cartCopy = cart;
                    allCarts.push_back(cartCopy);
                    cart = {};
                    cart.push_back(carriageCopy);
                }
            }
        }
    }
    carriage.push_back(stac);
    cart.push_back(carriage);
    allCarts.push_back(cart);
    return allCarts;
}

/**
 * Prints a message that confirms the number of carts, the biggest cart's number of carriages and the maximum amount of baggages that a stack can carry. It also shows a nice drawing of a cart and its carriages. Used in the simulation operation from the menu
 */
void Flight::printCarts(vector<vector<vector<stack<int>>>> carts) {
    cout << "Before your flight, you notice a Cart that is carrying the baggage to your flight\n" << endl;
    cout << "      O O O" << endl;
    cout << "   o O___  _________  _________  _________  _________" << endl;
    cout << " _][__|o|  |O O O O|  |O O O O|  |O O O O|  |O O O O|" << endl;
    cout << "<_______|--|_______|--|_______|--|_______|--|_______|" << endl;
    cout << " /O-O-O      o   o      o   o      o   o      o   o\n" << endl;
    cout << "You notice that there are " << carts.size() << " carts" << endl;
    cout << "And the biggest cart has " << carts[0].size() << " carriages" << endl;
    cout << "And those carriages have stacks that can hold up to " << stackMax << " baggages!\n" << endl;
}

/**
 *
 * @return The flight's number
 */
int Flight::getNumber() const {
    return number;
}

/**
 *
 * @return The flight's duration
 */
int Flight::getDuration() const {
    return duration;
}
/**
 *
 * @return The maximum amount of baggage that can go into a stack
 */
int Flight::getStackMax() {
    return stackMax;
}

/**
 *
 * @return The maximum number of stacks a carriage can have
 */
int Flight::getCarriageMax() {
    return carriageMaxSize;
}

/**
 *
 * @return maximum number of carriages a cart can have
 */
int Flight::getCartMax() {
    return cartMaxSize;
}

/**
 *
 * @return The date object representing the date of the flight's beginning
 */
Date& Flight::getDate() {
    return dateDeparture;
}

/**
 *
 * @return The airport object from which the journey starts
 */

Airport *Flight::getOrigin() {
    return origin;
}

/**
 *
 * @return The airport object from which the journey ends
 */

Airport *Flight::getDestiny() {
    return destiny;
}

/**
 *
 * @return The vector where all of the flight's ticket objects are stored
 */
vector<Ticket>& Flight::getTickets() {
    return tickets;
}

/**
 * It changes the flight's number to a new one
 * @param newNumber The new flight number
 */
void Flight::setNumber(int newNumber){
    number = newNumber;
}

/**
 * It changes the flight's duration to a new one
 * @param newDuration The date to replace the old one
 */
void Flight::setDuration(int newDuration){
    duration = newDuration;
}

/**
 * It prints all the tickets
 */
void Flight::printTickets() {
    for (int i = 0; i < tickets.size(); i++) {
        cout << i + 1 << ") ";
        tickets[i].print();
    }
}

/**
 * It prints all characteristics of the flight ( the flight number, the duration of the flight, the date, number of tickets and the airport's origin and destiny )
 */
void Flight::print() {
    cout << "Flight  Number: \t" << number << "   Duration: \t" << duration << "   Date of Departure: \t" << dateDeparture.getStringDate() << endl;
    cout << "        Airport Origin: \t" << origin->getName() << "      Airport Destiny: \t" << destiny->getName() << endl;
    cout << "        Number of tickets: \t" << tickets.size() << endl;
}

/**
 * Creates an Id for the airport in the origin of the journey
 * @param airport An airport
 */
void Flight::setAirportOrigin(Airport *airport) {
    this->origin = airport;
}

/**
 * Creates an Id for the airport in the destiny of the journey
 * @param airport An airport
 */
void Flight::setAirportDestiny(Airport *airport) {
    this->destiny = airport;
}

/**
 * It compares two numbers from 2 flights
 * @param flight1 flight one
 * @param flight2 flight two
 * @return returns true if the number of the flight 1 is lower than the number of the flight 2, otherwise, returns false
 */
bool Flight::compareByNumber(const Flight &flight1, const Flight &flight2) {
    return flight1.getNumber() < flight2.getNumber();
}

/**
 * It compares two durations from 2 flights
 * @param flight1 flight one
 * @param flight2 flight two
 * @return returns true if the duration of the flight 1 is lower than the duration of the flight 2, otherwise, returns false
 */
bool Flight::compareByDuration(const Flight &flight1, const Flight &flight2) {
    return flight1.getDuration() < flight2.getDuration();
}

/**
 * It compares two dates from 2 flights
 * @param flight1 flight one
 * @param flight2 flight two
 * @return returns true if the date of the flight 1 is lower than the date of the flight 2, otherwise, returns false
 */
bool Flight::compareByDate(Flight &flight1, Flight &flight2) {
    return flight1.getDate() < flight2.getDate();
}

/**
 * It compares two number of tickets from 2 flights
 * @param flight1 flight one
 * @param flight2 flight two
 * @return returns true if the number of tickets of the flight 1 is lower than the number of tickets of the flight 2, otherwise, returns false
 */
bool Flight::compareByNumberTickets(Flight &flight1, Flight &flight2) {
    return flight1.getTickets().size() < flight2.getTickets().size();
}






