#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Airport.h"
#include "../src/Passenger.h"
#include "../src/Flight.h"

using testing::Eq;

TEST(testAiport, AiportConstructor) {
    Airport airport1("1,Francisco Sa Carneiro");
    Airport airport2("3,Gatwick");
    EXPECT_EQ(1, airport1.getID());
    EXPECT_EQ("Francisco Sa Carneiro", airport1.getName());
    EXPECT_EQ(3, airport2.getID());
    EXPECT_EQ("Gatwick", airport2.getName());
}

TEST(testPassenger, PassengerConstructor) {
    Passenger passenger1("5,Ana Campos,217");
    Passenger passenger2("2,Alberto Jasmim,73");

    EXPECT_EQ(5, passenger1.getId());
    EXPECT_EQ("Ana Campos", passenger1.getName());
    EXPECT_EQ(217, passenger1.getAge());

    EXPECT_EQ(2, passenger2.getId());
    EXPECT_EQ("Alberto Jasmim", passenger2.getName());
    EXPECT_EQ(73, passenger2.getAge());
}