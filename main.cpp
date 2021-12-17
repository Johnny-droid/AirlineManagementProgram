#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <fstream>
#include "src/Menu.h"

using namespace std;

int main(int argc, char* argv[]) {

    string directory = "../DataFiles/";
    Menu menu(directory);
    menu.run(directory);

    /*
    testing::InitGoogleTest(&argc, argv);
    std::cout << "Airline Management Project" << std::endl;
    return RUN_ALL_TESTS();
    */
}


//     Macaco da Sorte
//          __
//     w  c(..)o   (
//      \__(-)    __)
//          /\   (
//         /(_)___)
//         w /|
//          | \
//         m  m
// Grande Macaco
// :)