#include "taxidriver.h"

TaxiDriver::TaxiDriver()
{
    _name = "";
    _age = 0;
    _salary = 0.0;
    _clients = 0;
}

TaxiDriver::TaxiDriver(string name, int age, double salary, int clients)
{
    _name = name;
    _age = age;
    _salary = salary;
    _clients = clients;
}

TaxiDriver::~TaxiDriver()
{

}

string TaxiDriver::name(){
    return _name;
}

int TaxiDriver::age(){
    return _age;
}

double TaxiDriver::salary(){
    return _salary;
}

int TaxiDriver::clients(){
    return _clients;
}
