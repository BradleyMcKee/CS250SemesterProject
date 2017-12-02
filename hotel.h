//Bradley McKee
#ifndef HOTEL_H
#define HOTEL_H


#include <iostream>
#include <string>
#include <fstream>
#include "floor.h"
#include "reservation.h"
#include <vector>
#include "date.h"

using namespace std;

class hotel{

    static double const singlebed  = 50.00;
    static double const doublebed  = 60.00;
    static double const specialroom  = 120;
    static double const tax  = .14;

public:
    vector<floor> allFloors;
    vector<reservation> allReservations;
    void readFloors(std::ifstream& in);
    void printHotelStatus();
    void updateRooms(std::ifstream& in);
};
#endif // HOTEL_H
