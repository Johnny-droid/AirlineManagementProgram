#include "LocalTransport.h"

/**
 * Creates a local transport object with defaut values for its attributes. These are -1 for the ID and distance to airport, an empty string for the transport type, and an empty list for the times
 */
LocalTransport::LocalTransport() {
    this->id = -1;
    this->typeTransport = "";
    this->times = list<Time>();
    this->distanceToAirport = -1;
}
/**
 * Creates a local transport object
 * @param id The local transport's ID
 * @param typeTransport The local transport's type (like subway, train or bus)
 * @param strTimes A string representing the local transport's full timetable
 * @param distanceToAirport The local transport's distance to its airport
 */
LocalTransport::LocalTransport(int id, string typeTransport, string strTimes, int distanceToAirport) {
    list<Time> lTimes;
    size_t pos = 0;
    while (pos != string::npos) {
        pos = strTimes.find_first_of(" ");
        if (pos == string::npos) {
            Time t1(strTimes);
            lTimes.push_back(t1);
            break;
        } else {
            string subStr = strTimes.substr(0, pos);
            Time t2(subStr);
            lTimes.push_back(t2);
            strTimes = strTimes.substr(pos + 1);
        }
    }

    this->id = id;
    this->typeTransport = typeTransport;
    this->times = lTimes;
    this->distanceToAirport = distanceToAirport;
}
/**
 *
 * @return The local transport's ID
 */
int LocalTransport::getId() const {
    return id;
}
/**
 *
 * @return The local transport's type (like subway, train or bus)
 */
string LocalTransport::getTypeTransport() const {
    return typeTransport;
}
/**
 *
 * @return A string representing the local transport's full timetable
 */
string LocalTransport::getStringTimes() const {
    string s;
    for (Time time : times) {
        s += time.getStringTime() + " ";
    }
    return s;
}
/**
 *
 * @return A list of the all the local transport's time objects
 */
list<Time>& LocalTransport::getTimes() {
    return times;
}
/**
 *
 * @return The local transport's distance to its airport
 */
int LocalTransport::getDistanceToAirport() const {
    return distanceToAirport;
}
/**
 * Change's the local transport's type to a new one
 * @param newTypeTransport The new type of the local transport
 */
void LocalTransport::setTypeTransport(string newTypeTransport){
    typeTransport = newTypeTransport;
}
/**
 * Change's the local transport's time object list to a new one
 * @param newTypeTransport The string representing a new list of time objects
 */
void LocalTransport::setTimes(string newTimes){
    list<Time> lTimes;

    while (newTimes.length() != 0) {
        int pos = newTimes.find_first_of("-");
        if (pos == newTimes.npos) {
            Time t1(newTimes);
            lTimes.push_back(t1);
            break;
        }
        string subStr = newTimes.substr(0, pos);
        Time t2(subStr);
        lTimes.push_back(t2);
        newTimes = newTimes.substr(pos + 1);
    }
    times = lTimes;
}
/**
 * Changes the local transport's distance to the airport into a new one
 * @param newDistanceToAirport The new distance to the airport
 */
void LocalTransport::setDistanceToAirport(int newDistanceToAirport){
    distanceToAirport = newDistanceToAirport;
}
/**
 * Print that represents the local transport object by showing its ID, type, full timetable, and distance to the airport
 */
void LocalTransport::print() const {
    cout << id << ") Local Transport    Type: " << typeTransport << "     times: " << this->getStringTimes() << endl;
    cout <<     "                       distance to Airport: " << distanceToAirport << "km" << endl;
}
/**
 * Checks if a local transport is closer to the airport than another local transport
 * @param lT The local transport on the right side of the < operator
 * @return True, if the first local transport's distance to the airport is smaller than the second local transport's. False, if otherwise.
 */
bool LocalTransport::operator<(const LocalTransport& lT) const {
    return this->distanceToAirport < lT.getDistanceToAirport();
}
/**
 * Checks if a local transport has the same distance to the airport as another local transport
 * @param lT The local transport on the right side of the == operator
 * @return True, if both local transports have the same value of distance to the airport. False, if otherwise.
 */
bool LocalTransport::operator==(const LocalTransport &lT) const {
    return this->id == lT.id;
}


