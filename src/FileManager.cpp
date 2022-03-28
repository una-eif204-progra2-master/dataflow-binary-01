//
// Created by Maikol Guzman Alan on 3/16/22.
//

#include "FileManager.h"
#include "vector"

/**
 * This function savePhysicalProduct data into Binary File
 * @param physicalProduct the object to savePhysicalProduct in the text file
 * @param fileName the name of the binary file
 */
void FileManager::savePhysicalProduct(const PhysicalProduct &physicalProduct, const string &fileName) {

    // Create and open a binary file
    ofstream myFile(fileName, ios_base::binary);

    // Write to the file
    myFile.write((char *)&physicalProduct, sizeof(physicalProduct));

    // Close the file
    myFile.close();
}

/**
 * Read data from a binary file
 * @param filename the name of the file
 * @return the object PhysicalProduct
 */
PhysicalProduct FileManager::readDataPhysicalProduct(const string &filename) {

    // Create file variable
    PhysicalProduct physicalProduct;

    // Read from the text file
    ifstream myReadFile(filename, ios::binary);

    if (!myReadFile.is_open()) {
        throw invalid_argument("Could not open the file [" + filename + "]");
    }

    // Read the binary file
    myReadFile.seekg (0);
    myReadFile.read((char*)&physicalProduct, sizeof(physicalProduct));

    // Close the file
    myReadFile.close();

    return physicalProduct;
}

/**
 * This function savePhysicalProductList data into Binary File
 * @param physicalProductList the object to savePhysicalProductList in the binary file
 * @param fileName the name of the binary file
 */
void FileManager::savePhysicalProductList(const vector<PhysicalProduct> &physicalProductList, const string &fileName) {

    // Create and open a binary file
    ofstream myFile(fileName, ios_base::binary);

    // Write to the file
    for (auto &physicalProduct : physicalProductList) {
        myFile.write((char *)&physicalProduct, sizeof(physicalProduct));
    }

    // Close the file
    myFile.close();
}

/**
 * Read data from a binary file
 * @param filename the name of the file
 * @return the object list PhysicalProduct
 */
vector<PhysicalProduct> FileManager::readDataPhysicalProductList(const string &filename) {

    // Create file variable
    vector<PhysicalProduct> physicalProductList;
    PhysicalProduct physicalProduct;

    // Read from the text file
    ifstream myReadFile(filename, ios::binary);

    if (!myReadFile.is_open()) {
        throw invalid_argument("Could not open the file [" + filename + "]");
    }

    // Read the binary file
    myReadFile.seekg (0);
    while(myReadFile.read((char*)&physicalProduct, sizeof(physicalProduct))){
        physicalProductList.push_back(physicalProduct);
    }

    // Close the file
    myReadFile.close();

    return physicalProductList;
}


