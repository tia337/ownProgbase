#ifndef TAXIDRIVER_H
#define TAXIDRIVER_H
#include <iostream>
using namespace std;

class TaxiDriver
{
    string _name;
    int _age;
    double _salary;
    int _clients;
public:
    TaxiDriver();
    TaxiDriver(string name, int age, double salary, int clients);
    ~TaxiDriver();
    string name();
    int age();
    double salary();
    int clients();
};

#endif // TAXIDRIVER_H
