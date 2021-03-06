#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <fstream>
#include "src/Menu.h"

using namespace std;

int main(int argc, char* argv[]) {
    string directory = "../DataFiles/";
    string directorySave = "../DataFilesSaved/";
    Menu menu(directory, directorySave);
    menu.run();
    /*
    testing::InitGoogleTest(&argc, argv);
    std::cout << "Airline Management Project" << std::endl;
    return RUN_ALL_TESTS();
    */
}
