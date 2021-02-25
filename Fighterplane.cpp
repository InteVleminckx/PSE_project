//
//  Fighterplane.cpp
//
//  Created by Quinten Soetens on 13/02/14.
//  Copyright (c) 2014 Quinten Soetens. All rights reserved.
//

#include <fstream>


class Fighterplane{
private:
    std::string callsign;
    int x; //positional coordinate
    int y; //positional coordinate
    int z; //positional coordinate
    int ammo; //keeps track of the number of missiles
    int health; //the remaining hitpoints the plane still has. When this reaches 0 the plane is dead!
public:
    //Default constructor will place a new plane with no name at location (0,0,0)
    Fighterplane() {
        this->callsign = "";
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }
    
    //constructor to set a plane on a certain location.
    //ammo and healt are automaticalle initialized to 10 and 20 respectively
    Fighterplane(std::string callsign, int x, int y, int z) : ammo(10), health(20){
        this->callsign = callsign;
        this->x = x;
        this->y = y;
        this->z = z;
    }
    
    std::string getCallSign(){
        return callsign;
    }
    
    //Obtain positional coordinate in string format
    int getCoords(){
        return x;
    }
    //Getter to obtain positional coordinate
    int getY(){
        return y;
    }
    //Getter to obtain positional coordinate
    int getZ(){
        return z;
    }
    
    //Method that allows a plane to move to a new location.
    void moveTo(int x, int y, int z){
        this->x += x;
        this->y += y;
        this->z += z;
    }
    
    //Method to attack another plane.
    void attackPlane(Fighterplane* target){
        this->ammo -= 1;
        target->health -= 5;
    }
    
    //Prints all the information about this fighterplane to a file.
    void printToFile(const char * filename){
        std::ofstream outfile;
        outfile.open (filename);
        outfile << "Information about Fighterplane: \n";
        outfile << "Callsign: " + callsign + "\n";
        outfile << "Position: (" << x << "," << y << "," << z << ")\n";
        outfile << "Health: " << health << "\n";
        outfile << "Remaining ammo: " << ammo << "\n";
        outfile.close();
    }
};
