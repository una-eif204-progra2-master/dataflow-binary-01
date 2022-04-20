//
// Created by Maikol Guzman Alan on 3/16/22.
//

#include "FileManager.h"

/**
 * This function savePhysicalProduct data into Binary File
 * @param physicalProduct the object to savePhysicalProduct in the text file
 * @param fileName the name of the binary file
 */
void FileManager::savePhysicalProduct(const PhysicalProduct &physicalProduct, const string &fileName) {

    // Create and open a binary file
    ofstream myFile(fileName, std::ios::out | std::ios::binary | std::ios::app);

    // Write to the file
    write(myFile, physicalProduct);

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
    ifstream myReadFile(filename, ios::in | ios::binary);

    if (!myReadFile.is_open()) {
        throw invalid_argument("Could not open the file [" + filename + "]");
    }

    // Read the binary file
    myReadFile.seekg (0);
    read(myReadFile, physicalProduct);

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
    ofstream myFile(fileName, ios::out | ios_base::binary);

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
    ifstream myReadFile(filename, ios::in | ios::binary);

    if (!myReadFile.is_open()) {
        throw invalid_argument("Could not open the file [" + filename + "]");
    }

    // Read the binary file
    // myReadFile.seekg (sizeof(physicalProduct),ios::beg);  // Reading the last value
    myReadFile.seekg (0);
    while(myReadFile.read((char*)&physicalProduct, sizeof(physicalProduct))){
        physicalProductList.push_back(physicalProduct);
    }

    // Close the file
    myReadFile.close();

    return physicalProductList;
}

ostream &FileManager::write(ostream &out, const PhysicalProduct &physicalProduct) {
    double price = physicalProduct.getPrice();
    double weight = physicalProduct.getWeight();
    size_t len = physicalProduct.getName().size();

    out.write((char*)&len, sizeof(len));
    out.write(physicalProduct.getName().c_str(), len);
    out.write((char*)(&price), sizeof(physicalProduct.getPrice()));
    out.write((char*)(&weight), sizeof(physicalProduct.getWeight()));

    return out;
}

istream &FileManager::read(istream &in, PhysicalProduct &physicalProduct) {
    size_t len = 0;
    in.read((char*)&len, sizeof(len));

    double price = 0.0, weight = 0.0;

    char* name = new char[len + 1];
    in.read(name, len);
    name[len] = '\0';
    physicalProduct.setName(name);
    delete[] name;

    in.read((char*)&price, sizeof(double));
    in.read((char*)&weight, sizeof(double));
    physicalProduct.setPrice(price);
    physicalProduct.setWeight(weight);

    return in;
}


