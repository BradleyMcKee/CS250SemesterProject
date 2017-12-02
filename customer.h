//Bradley McKee
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <fstream>
#include "date.h"
#include <vector>
#include <sstream>


using namespace std;

struct customer{
    customer(){};
    customer(string name, string username, string address, string phone, string email, string pID, string ccNumber, string ccDate, string ccName)
    {
        string dayStr, monthStr, yearStr;
        int day, month, year;
        nameofCustomer = name;
        customerUsername = username;
        address = address;
        phoneNum = phone;
        email_id = email;
        uniqueID = pID;
        ccNumber = cardNum;
        typecard = ccName;
        dayStr = ccDate.substr(0,2);
        monthStr = ccDate.substr(3,5);
        yearStr = ccDate.substr(6,8);
        istringstream bufferDay(dayStr);
        bufferDay >> day;
        istringstream bufferMonth(monthStr);
        bufferMonth >> month;
        istringstream bufferYear(yearStr);
        bufferYear >> year;
        Date newDate(day,month,year);
        expiration = newDate;
    }
    string nameofCustomer;
    string customerUsername;
    string address;
    string phoneNum;
    string email_id;
    string uniqueID;
    string cardNum;
    Date expiration;
    string typecard;

    void read(std::ifstream& in);
};



#endif // CUSTOMER_H
