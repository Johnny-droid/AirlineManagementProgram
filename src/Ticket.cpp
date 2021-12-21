#include "Ticket.h"
/**
 * Creates a ticket object
 * @param baggage The amount of baggage that owner of the ticket can carry
 * @param price The price of the ticket
 * @param passenger The passenger object representing the ticket's owner
 */
Ticket::Ticket(int baggage, int price, Passenger* passenger) {
    this->baggage = baggage;
    this->price = price;
    this->passenger = passenger;
}
/**
 *
 * @return The amount of baggage
 */
int Ticket::getBaggage() {
    return baggage;
}
/**
 *
 * @return The ticket's price
 */
int Ticket::getPrice() {
    return price;
}
/**
 *
 * @return The passenger object representing the ticket's owner
 */
Passenger* Ticket::getPassenger() {
    return passenger;
}
/**
 * Changes the baggage amount to a new one
 * @param newBaggage The new baggage amount
 */
void Ticket::setBaggage(int newBaggage){
    baggage = newBaggage;
}
/**
 * Changes the price to a new one
 * @param newPrice The new price
 */
void Ticket::setPrice(int newPrice){
    price = newPrice;
}
/**
 * Changes the passenger object to a new one
 * @param newPassenger The passenger object representing the ticket's new owner
 */
void Ticket::setPassenger(Passenger* newPassenger){
    passenger = newPassenger;
}
/**
 * Print that represents the ticket object by showing its owner's name, baggage amount and price
 */
void Ticket::print() {
    cout << "Ticket    Passenger: " << passenger->getName() << "     Baggage: " << baggage << "       Price: " << price << endl;
}
/**
 * Compares two tickets by their baggage amount
 * @param ticket1 The first ticket
 * @param ticket2 The second ticket
 * @return True, if the first ticket's baggage amount is smaller than the second ticket's. False, if otherwise.
 */
bool Ticket::compareByBaggage(const Ticket& ticket1, const Ticket& ticket2) {
    return ticket1.baggage < ticket2.baggage;
}
/**
 * Compares two tickets by their price
 * @param ticket1 The first ticket
 * @param ticket2 The second ticket
 * @return True, if the first ticket's price is lower than the second ticket's. False, if otherwise.
 */
bool Ticket::compareByPrice(const Ticket& ticket1, const Ticket& ticket2) {
    return ticket1.price < ticket2.price;
}
/**
 * Compares two tickets by their owner's name
 * @param ticket1 The first ticket
 * @param ticket2 The second ticket
 * @return True, if the first ticket's owner's name is alphabetically before the second ticket's. False, if otherwise.
 */
bool Ticket::compareByPassenger(const Ticket &ticket1, const Ticket &ticket2) {
    return ticket1.passenger->getName() < ticket2.passenger->getName();
}
