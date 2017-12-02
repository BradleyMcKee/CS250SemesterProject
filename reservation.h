//Bradley McKee
#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>
#include "date.h"



struct reservation{
    reservation(int roomNumber, string name, Date in, Date out, int staying, int price)
    {
        roomNum = roomNumber;
        customerName = name;
        checkin = in;
        checkout = out;
        lengthOfStay = staying;
        rateofRoom = price;
    }
    int roomNum;
    string customerName;
    Date checkin;
    Date checkout;
    int lengthOfStay;
    int rateofRoom;
};
#endif // BOOKING_H
