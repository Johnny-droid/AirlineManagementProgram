#ifndef AIRLINEMANAGEMENTPROGRAM_SERVICE_H
#define AIRLINEMANAGEMENTPROGRAM_SERVICE_H

#include <string>

using namespace std;

class Service {
    string typeOfService;
    string date;
    string worker;
public:
    Service(string typeOfService, string date, string worker);
    string getTypeOfService();
    string getDate();
    string getWorker();
};


#endif //AIRLINEMANAGEMENTPROGRAM_SERVICE_H
