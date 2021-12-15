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

TEST(testAiport, Aiports) {
    vector<string> v1 =  Menu::split("1,Francisco Sa Carneiro");
    vector<string> v2 = Menu::split("3,Gatwick");

    Airport airport1(stoi(v1[0]), v1[1]);
    Airport airport2(stoi(v2[0]), v2[1]);
}

TEST(testPassenger, Passengers) {
    vector<string> v1 =  Menu::split("5,Ana Campos,217");
    vector<string> v2 = Menu::split("6,Pablo Escobar,72");

    Passenger passenger1(stoi(v1[0]), v1[1], stoi(v1[2]));
    Passenger passenger2(stoi(v2[0]), v2[1], stoi(v2[2]));
}

TEST(testMenu, testSplitFunction) {
    cout << "Testing split function" << endl;
    vector<string> v1 = Menu::split("");
    vector<string> v2 = Menu::split("Hey, numeber 42, give me the answer, now!");

    EXPECT_TRUE(v1.empty());

    EXPECT_EQ(4, v2.size());
    EXPECT_EQ("Hey", v2[0]);
    EXPECT_EQ(" numeber 42", v2[1] );
    EXPECT_EQ(" give me the answer", v2[2] );
    EXPECT_EQ(" now!", v2[3]);

}

TEST(testService, ServiceConstructor) {

}

TEST(testPlane, PlaneConstructor) {

}