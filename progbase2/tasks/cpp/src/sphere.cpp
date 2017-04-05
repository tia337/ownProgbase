#include <iostream>
#include <sphere.h>
#include <cmath>

Sphere :: Sphere(string new_name, int new_centerX, int new_centerY, int new_centerZ, int new_radius){
    name = new_name;
    centerX = new_centerX;
    centerY = new_centerY;
    centerZ = new_centerZ;
    radius = new_radius;
}

double Sphere :: SphereVolume(void){
    double pi = 3.14;
    double volume = 4*pi*(pow(radius,3))/3;
    return volume;
}
void Sphere :: outSphere(void){
    cout << "name: " << name << endl;
    cout << "centerX: " << centerX << endl;
    cout << "centerY: " << centerY << endl;
    cout << "centerZ: " << centerZ << endl;
    cout << "radius: " << radius << endl;
}
Sphere :: ~Sphere(){}