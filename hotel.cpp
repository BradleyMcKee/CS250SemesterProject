#include "hotel.h"

using namespace std;
//FUNCTIONS REGARDING THE NUMBER OF ROOMS IN THE HOTEL
void hotel::readFloors(ifstream& in)
{
    string description[16];
    int hotelArr[16];
    for(int i = 0;i<16;i++)
    {
        in >> hotelArr[i]
           >> description[i];
    }
    vector<floor> allfloors[hotelArr[0]];
    for(int i=1; i<(hotelArr[0]+1); i++)
    {
        floor newFloor(hotelArr[(i*4)-3], hotelArr[(i*4)-2], hotelArr[(i*4)-1], hotelArr[(i*4)]);
        allFloors.push_back(newFloor);
        if(hotelArr[i+12]==1)
        {
            allFloors[i-1].smokingType = true;
        }
    }
}
void hotel::updateRooms(std::ifstream& in)
{
    string currentLine;
    do
    {
        string fname,lname,name,trash;
        int roomNum,inYear,inMonth,inDay,outYear,outMonth,outDay, stayLength, price;
        in >> roomNum >> fname >> lname >> inYear >> inMonth >> inDay >> outYear >> outMonth >> outDay >> stayLength >> price >> trash;
        int roomFloor = roomNum/100;
        int roomNumber = roomNum%100;
        Date checkedIn(inDay, inMonth, inYear);
        Date checkedOut(outDay, outMonth, outYear);
        reservation newRes(roomNum, (fname + " " + lname), checkedIn, checkedOut, stayLength, price);
        allReservations.push_back(newRes);
        if(allFloors[roomFloor-1].singleRooms.size()>= roomNumber)
        {
            allFloors[roomFloor-1].singleRooms[roomNumber-1].vacancy = "ocpy";
        }
        else if(roomNumber <allFloors[roomFloor-1].totalRooms && allFloors[roomFloor-1].singleRooms.size()<= roomNumber)
        {
            allFloors[roomFloor-1].doubleRooms[roomNumber - allFloors[roomFloor-1].doubleRooms.size() - 1].vacancy = "ocpy";
        }
        else
            allFloors[roomFloor-1].specialRoom.vacancy = "ocpy";
    }
    while(getline(in,currentLine));
}

void hotel::printHotelStatus()
{
    string lines = "--------------------------------------------------------------------------------";
    string hashtag = " ###############################################################################";
    string floor3 = "#       #       #       #       #       #       #       #       #              #";
    string floor2 = "#       #       #       #       #       #       #       #                      #";
    string floor1 = "#       #       #       #       #       #       #                              #";
    cout << lines << "                          Welcome to Hotel Booking System" << endl<<lines
    << "                                   Hotel Status" << endl<< lines<< hashtag<< floor3;
    for(int i=(allFloors.size()-1);i>=0;i--)
    {
        if(allFloors[i].smokingType)
        {
            for(int j=0;j<allFloors[i].singleRooms.size();j++)
            {
                cout<< "# SSMK  ";
            }
            for(int j=0;j<allFloors[i].doubleRooms.size();j++)
            {
                cout<< "# DSMK  ";
            }
            if(allFloors[i].totalRooms == 9)
                cout<< "#      SPC3    #" << floor3;
            else
                cout<< "#              SPC1            #" << floor1;
        }
        else
        {
            for(int j=0;j<allFloors[i].singleRooms.size();j++)
            {
                cout<< "# SNSK  ";
            }
            for(int j=0;j<allFloors[i].doubleRooms.size();j++)
            {
                cout<< "# DNSK  ";
            }
            cout << "#          SPC2        #" << floor2;
        }
        for(int j=1; j<=allFloors[i].totalRooms;j++)
        {
            if(j==allFloors[i].totalRooms)
            {
                switch (i)
                {
                case 2:
                    cout << "#      309     #";
                    break;
                case 1:
                    cout << "#          208         #";
                    break;
                case 0:
                    cout << "#              107             #";
                }
            }
            else
                cout<<"# " << (i+1) << "0" << j << "   ";
        }
        switch (i)
        {
        case 2:
            cout << floor3;
            break;
        case 1:
            cout << floor2;
            break;
        case 0:
            cout << floor1;
            break;
        }
        for(int x=0; x<allFloors[i].singleRooms.size();x++)
        {
            cout << "# " << allFloors[i].singleRooms[x].vacancy << "  ";
        }
        for(int j=0; j<allFloors[i].doubleRooms.size();j++)
        {
            cout << "# " << allFloors[i].doubleRooms[j].vacancy << "  ";
        }
        switch (i)
        {
        case 2:
            cout << "#      " << allFloors[i].specialRoom.vacancy << "    #" << floor3 << hashtag << floor2;
            break;
        case 1:
            cout << "#          " << allFloors[i].specialRoom.vacancy << "        #" << floor2 << hashtag << floor1;
            break;
        case 0:
            cout << "#              " << allFloors[i].specialRoom.vacancy << "            #" << floor1 << hashtag;
        }
    }
}
