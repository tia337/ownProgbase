#ifndef SPHERE_H
#define SPHERE_H

using namespace std;
#include <string>

class Sphere {
    string name;
    int centerX;
    int centerY;
    int centerZ;
    int radius; 
    public:     
    Sphere();
    ~Sphere();
    Sphere(string name, int centerX, int centerY, int centerZ, int radius);
    double SphereVolume(void);
    void outSphere(void);
};



#endif