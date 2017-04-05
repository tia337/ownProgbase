#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include <iostream>
using namespace std;

class MoreData
{
    int _matanPoints;
    int _students;
};

class University
{
    string _name;
    string _location;
    double _rank;
    MoreData data;
public:
    University();
    ~University();
    getName();
    getLocation();
    getRank();
    getMoreData();
};


#endif // UNIVERSITY_H
