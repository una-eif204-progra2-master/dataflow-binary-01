//
// Created by Maikol Guzman Alan on 3/16/22.
//

#ifndef MY_PROJECT_NAME_FILEMANAGER_H
#define MY_PROJECT_NAME_FILEMANAGER_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "PhysicalProduct.h"

using namespace std;

class FileManager {
public:
    /**
     * This function savePhysicalProduct data into Binary File
     * @param physicalProduct the object to savePhysicalProduct in the binary file
     * @param fileName the name of the binary file
     */
    static void savePhysicalProduct(const PhysicalProduct& physicalProduct, const string& fileName);

    /**
     * Read data from a binary file
     * @param filename the name of the file
     * @return the object PhysicalProduct
     */
    static PhysicalProduct readDataPhysicalProduct(const string& filename);

    /**
     * This function savePhysicalProductList data into Binary File
     * @param physicalProductList the object to savePhysicalProductList in the binary file
     * @param fileName the name of the binary file
     */
    static void savePhysicalProductList(const vector<PhysicalProduct>& physicalProductList, const string& fileName);

    /**
     * Read data from a binary file
     * @param filename the name of the file
     * @return the object list PhysicalProduct
     */
    static vector<PhysicalProduct> readDataPhysicalProductList(const string& filename);

    /**
    * Method to write in files with at least one type of std::string
    **/
    static ostream& write(ostream& out, const PhysicalProduct& physicalProduct);

    /**
    * Method to read from files with at least one type of std::string
    **/
    static istream& read(istream& in, PhysicalProduct& physicalProduct);
};


#endif //MY_PROJECT_NAME_FILEMANAGER_H
