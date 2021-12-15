#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Airport.h"

using testing::Eq;

TEST(testAiport, AiportConstructor) {
    Airport airport1("1,Francisco Sa Carneiro");
    Airport airport2("3,Gatwick");
    EXPECT_EQ(1, airport1.getID());
    EXPECT_EQ("Francisco Sa Carneiro", airport1.getName());
    EXPECT_EQ(3, airport2.getID());
    EXPECT_EQ("Gatwick", airport2.getName());
}
