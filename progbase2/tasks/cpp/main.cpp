#include <iostream>
#include <sphere.h>
#include <vector>


    int main(){
        vector<Sphere*>first;
        int centerX;
        int centerY;
        int centerZ;
        int radius; 
        string pause;
        char option = '0';
            cout << "press 1 to add new element" << endl; 
            cout << "press 2 to output containing!" << endl; 
            cout << "press 3 to output all spheres with volume bigger then inputed" << endl; 
            cout << "press 4 to quit!" << endl; 
         while(option != '4') {
            option = getchar();
            switch(option){
                case '1':{
                    system("clear");
                    cout << "Enter element`s data" << endl;
                    string name;
                    cin >> name >> centerX >> centerY >> centerZ >> radius;
                    //Sphere * one = new Sphere(name, centerX, centerY, centerZ, radius);
                    first.insert(first.end(), new Sphere(name, centerX, centerY, centerZ, radius));
                    cout << "press any key to go forward or 4 for two times to exit" << endl; 
                    getline(cin, pause);
                    getline(cin, pause);
                    system("clear");
                    break;
                }
                case '2':{
                    system("clear");
                    cout << "Here are all elements in the list" << endl;
                    int size = first.size();
                    for(int i = 0; i < size; i++){
                       first[i]->outSphere(); 
                    }
                    cout << "press any key to go forward or 4 for two times to exit" << endl;  
                    getline(cin, pause);
                    getline(cin, pause);
                    system("clear");
                    break; 
                }
                case '3':{
                    int volume;
                    system("clear");
                    cout << "enter the volume" << endl; 
                    cin >> volume;
                    for(int i = 0; i< first.size(); i++){
                        if(first[i]->SphereVolume() < volume){
                            first[i]->outSphere();
                        }
                    }
                    cout << "press any key to go forward or 4 for two times to exit" << endl;  
                    getline(cin, pause);
                    getline(cin, pause);
                    system("clear");
                    break;
                }
                case '4':
                    //exit
                    break;
                default:{
                    system("clear");
                    cout << "enter another key" << endl;
                    getline(cin, pause);
                    getline(cin, pause);
                    system("clear");
                    break;
                }
            }
        }
        for(int i = 0; i < first.size(); i++) {
            delete first[i];
        }
        return 0;
    }