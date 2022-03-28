//
// Created by Maikol Guzman Alan on 3/1/22.
//

#ifndef SOLID_01_SRP_PRODUCT_H
#define SOLID_01_SRP_PRODUCT_H
#include <iostream>
#include <sstream>
using namespace std;

class Product {
private:
    string name;
    double price;

    virtual double applyDiscount();
public:
    Product();

    virtual ~Product();

    virtual double convertPrice();

    const string &getName() const;

    void setName(const string &name);

    double getPrice() const;

    void setPrice(double price);

    friend ostream &operator<<(ostream &os, const Product &product);

    string toString() const;
};


#endif //SOLID_01_SRP_PRODUCT_H
