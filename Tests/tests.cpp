#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "../src/Airport.h"
#include "../src/Passenger.h"
#include "../src/Plane.h"
#include "../src/Flight.h"
#include "../src/Service.h"
#include "../src/Ticket.h"
#include "../src/LocalTransport.h"
#include "../src/Menu.h"

using testing::Eq;

/*
  Criar um aviao funciona (Option 1:1)
  Ler os aviões funciona, incluindo o novo criado (Option2:1)
  Dar update a um avião funciona, quer dar update á license incluindo no avião novo e quando fazes update aparece a lista dos aviões (Option 3:1)
  Dar remove a um avião funciona (Option 4:1)



 */


TEST(testOverall, creation) {
    Menu menu;
    Plane plane1("A45623", 320);

    menu.getPlanes().push_back(plane1);
    EXPECT_EQ( "A45623", menu.getPlanes()[0].getLicensePlate());
    EXPECT_EQ(320, menu.getPlanes()[0].getCapacity());
}

TEST(testOverall, update) {
    Menu menu;
    Plane milleniumFalcon("B6666", 423);
    menu.getPlanes().push_back(milleniumFalcon);
    EXPECT_EQ("B6666", menu.getPlanes()[0].getLicensePlate());
    EXPECT_EQ(423, menu.getPlanes()[0].getCapacity());
}

TEST(testOverall, remove) {

}

TEST(testAiport, Aiports) {
    // depois adicionar testes com a BST
    cout << "\n\nTesting Airport Constructor" << endl;
    vector<string> v1 =  Menu::split("1,Francisco Sa Carneiro", ",");
    vector<string> v2 = Menu::split("3,Gatwick", ",");

    Airport airport1(stoi(v1[0]), v1[1]);
    Airport airport2(stoi(v2[0]), v2[1]);
    EXPECT_EQ(1, airport1.getId());
    EXPECT_EQ("Francisco Sa Carneiro", airport1.getName());
    EXPECT_EQ(3, airport2.getId());
    EXPECT_EQ("Gatwick", airport2.getName());

}

TEST(testPassenger, Passengers) {
    cout << "\nTesting Passenger Constructor" << endl;
    vector<string> v1 =  Menu::split("5,Ana Campos,217", ",");
    vector<string> v2 = Menu::split("6,Pablo Escobar,72", ",");

    Passenger passenger1(stoi(v1[0]), v1[1], stoi(v1[2]));
    Passenger passenger2(stoi(v2[0]), v2[1], stoi(v2[2]));
}

TEST(testMenu, testSplitFunction) {
    cout << "\nTesting split function" << endl;
    vector<string> v1 = Menu::split("", "");
    vector<string> v2 = Menu::split("Hey, numeber 42, give me the answer, now!", ",");

    EXPECT_TRUE(v1.empty());

    EXPECT_EQ(4, v2.size());
    EXPECT_EQ("Hey", v2[0]);
    EXPECT_EQ(" numeber 42", v2[1] );
    EXPECT_EQ(" give me the answer", v2[2] );
    EXPECT_EQ(" now!", v2[3]);

}

TEST(testMenu, Menu_Initialization) {
    cout << "\nTesting Menu initialization" << endl;
    Menu menu("../DataFiles/");
    // depois de tu, antónio, alterares os ficheiros coloca-se alguns testes aqui de acordo com o que estiver:
    // do tipo:
    //EXPECT_EQ( número de aviões, menu.getPlanes().size());
    EXPECT_EQ( "A310", menu.getPlanes()[0].getLicensePlate());
    EXPECT_EQ( "Pablo Escobar"  , menu.getPlanes()[0].getFlightPlan()[0].getTickets()[0].getPassenger()->getName());
}

TEST(testMenu, PrintPlanes) {
    Menu menu("../DataFiles/");
    menu.printPlanes();
}

TEST(testMenu, Print_Menu_Initialization) {
    Menu menu("../DataFiles/");
    for (Plane plane : menu.getPlanes()) {
        cout << "\n\n\nPLANE " << plane.getLicensePlate() << endl;

        queue<Service> services = plane.getServicesToBeDone();
        while (!services.empty()) {
            Service service = services.front();
            cout << "\nService: " << service.getTypeOfService() << "  " << service.getDate() << "  " << service.getWorker() << endl;
            services.pop();
        }

        vector<Flight> flights = plane.getFlightPlan();
        for (Flight flight : flights) {
            cout << "\nFlight: " << flight.getNumber() << "      Duration: " << flight.getDuration() << endl;
            cout << "Airport    Origin: " << flight.getOrigin()->getName() << "      Destiny:  " << flight.getDestiny()->getName() << endl;

            for (Ticket ticket : flight.getTickets()) {
                cout << "Ticket  Price: " << ticket.getPrice() << "   Baggage:   " << ticket.getBaggage() << endl;
                cout << "Passenger of the ticket: " << ticket.getPassenger()->getName() << endl;
            }
        }
    }
}


