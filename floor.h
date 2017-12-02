//Bradley McKee
#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
#include <fstream>
#include <vector>
#include "room.h"

using namespace std;

class floor{

public:
    floor(int total, int single, int dbl, int special)
    {
        totalRooms = total;
        singleRooms.resize(single);
        doubleRooms.resize(dbl);
    }
    int totalRooms;
    vector<room> singleRooms;
    vector<room> doubleRooms;
    room specialRoom;
    bool smokingType = false;

};
#endif // FLOOR_H
