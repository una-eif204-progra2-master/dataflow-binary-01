//
// Created by Maikol Guzman Alan on 3/16/22.
//
#include <stdlib.h>
#include <time.h>
#include <stdexcept>
#include <vector>

#include "FileManager.h"
using namespace std;

int main() {
    std::cout << "Welcome to the UNA! (VIRTUAL)\n" << std::endl;

    try {
        /* initialize random seed: */
        srand (time(NULL));

        PhysicalProduct physicalProduct1;
        physicalProduct1.setName("PS5 Game: Call of Duty");
        physicalProduct1.setType("PS5");
        physicalProduct1.setWeight(500);
        physicalProduct1.setPrice(59);

        PhysicalProduct physicalProduct2;
        physicalProduct2.setName("PS5 Game: Fifa");
        physicalProduct1.setType("PS5");
        physicalProduct2.setWeight(rand() % 500);
        physicalProduct2.setPrice(rand() % 59 + 100);

        // Manager SRP
        FileManager fileManager;

        // This function will savePhysicalProduct the information of the
        // Physical Product in a file with the name games1.dat
        fileManager.savePhysicalProduct(physicalProduct1, "games1.dat");

        // This function read a binary file
        PhysicalProduct physicalProductData = fileManager.readDataPhysicalProduct("games1.dat");

        cout << "[FILE BINARY READ]" << endl;
        cout << physicalProductData << endl;

        vector<PhysicalProduct> physicalProductList;
        physicalProductList.push_back(physicalProduct1);
        physicalProductList.push_back(physicalProduct2);

        // This function will savePhysicalProduct the information of the
        // Physical Product in a file with the name games2.dat
        fileManager.savePhysicalProductList(physicalProductList, "games2.dat");

        // This function read a binary file
        vector<PhysicalProduct> physicalProductListData = fileManager.readDataPhysicalProductList("games2.dat");

        cout << "[FILE BINARY READ WITH VECTOR]" << endl;
        for (auto &physicalProduct : physicalProductListData) {
            cout << physicalProduct << endl;
        }

    } catch (exception& ex) {
        cerr << ex.what() << '\n' << std::endl;
    }
    return 0;
}