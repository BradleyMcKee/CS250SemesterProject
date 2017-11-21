#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "hotel.h"
#include "customer.h"
#include "manager.h"
#include <ctime>

using namespace std;

int main()
{
    //Get todays date
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    int year = now->tm_year + 1900;
    int month = now-> tm_mon + 1;
    int day = now->tm_mday;

    //Creates the hotel and Outputs hotel status
    ifstream hotelComp;
    hotelComp.open("hotelinput.txt");
    hotel hotel;
    hotel.readFloors(hotelComp);

    //Remembers all of the customers and stores their information
    string currentline;
    vector<customer> custArray;
    ifstream customerFile;
    customerFile.open("customer.txt");
    do
    {
        customer temp;
        temp.read(customerFile);
        custArray.push_back(temp);
        getline(customerFile,currentline);
    }
    while(getline(customerFile,currentline));
    //Creates the manager
    manager hotelManager;
    ifstream managerFile;
    managerFile.open("manager.txt");
    hotelManager.readMan(managerFile);
    managerFile.close();

    ifstream bookingFile;
    bookingFile.open("bookings.txt");
    hotel.updateRooms(bookingFile);
    bookingFile.close();

    string lines = "--------------------------------------------------------------------------------";
    string mainMenu = "\n\n\nMain Menu\n\nPress 1 to login as a customer(Only for registered customers)\nPress 2 to register as a customer\nPress 3 to login as a manager\nPress 4 to close the program\n\n--------------------------------------------------------------------------------\nEnter your choice: ";
    string customerMenu = "\nCustomer Menu\n\nPress 1 to view rooms status for today\nPress 2 to view rooms status on a date you enter\nPress 3 to Book a Room\nPress 4 to logout and go to main menu\n\n--------------------------------------------------------------------------------\nEnter your choice: ";
    string managerMenu = "\nManager Menu\n\nPress 1 to list occupied rooms Today\nPress 2 to list free rooms today\nPress 3 to view todays bookings\nPress 4 to view todays departures\nPress 5 to view todays financial earnings\nPress 6 to Add a booking\nPress 7 to Remove a booking\nPress 8 to view any days booking\nPress 9 to view all customers usernames\nPress 10 to view a customer's details\nPress 11 to go back to main menu\n\n--------------------------------------------------------------------------------\nEnter your choice: ";
    string userChoice;
    do
    {
        hotel.printHotelStatus();
        cout << mainMenu;
        getline(cin,userChoice);
        if(userChoice.compare("1")==0)
        {
            //FOR LOOP GOES THROUGH CUSTARRAY, THEN IF PSW AND USERNAME IS EQUAL LOG IN
            string name, username;
            cout << "Enter your name: ";
            getline(cin,name);
            cout << "\Enter your username to confirm login: ";
            getline(cin, username);
            int correctName = 0;
            for(int i=0; i<custArray.size();i++)
            {
                if(custArray[i].nameofCustomer.compare(name)==0 && custArray[i].customerUsername.compare(username)==0)
                {
                    string customerChoice;
                    do
                    {
                        cout << "\n" << lines << "\nHello " << name << " !!\n";
                        cout << customerMenu;
                        getline(cin, customerChoice);
                        if(customerChoice.compare("1") == 0)
                        {
                            for(int j=0; j<hotel.allReservations.size();j++)
                            {
                                if(hotel.allReservations[j].customerName.compare(custArray[i].nameofCustomer) == 0)
                                {
                                    if(hotel.allReservations[j].checkin.month == month && hotel.allReservations[j].checkin.year == year && hotel.allReservations[j].checkin.day == day)
                                    {
                                            cout << "\nToday's Booking Information\nRoom Number :" << hotel.allReservations[j].roomNum <<
                                            " - Booked Today - Booked By - " << custArray[i].nameofCustomer;
                                    }
                                }
                            }
                        }
                        else if(customerChoice.compare("2") == 0)
                        {
                            int searchDay, searchMonth, searchYear;
                            cout << "Enter the day (DD): ";
                            cin >> searchDay;
                            cout << "Enter the month (MM): ";
                            cin >> searchMonth;
                            cout << "Enter the year (YYYY): ";
                            cin >> searchYear;
                            for(int j=0; j<hotel.allReservations.size();j++)
                            {
                                if(hotel.allReservations[j].customerName.compare(custArray[i].nameofCustomer) == 0)
                                {
                                    if(hotel.allReservations[j].checkin.month == searchMonth && hotel.allReservations[j].checkin.year == searchYear && hotel.allReservations[j].checkin.day == searchDay)
                                    {
                                            cout << "\nBooking Information\nRoom Number : " << hotel.allReservations[j].roomNum <<
                                            " - Booked By - " << custArray[i].nameofCustomer;
                                    }
                                    else
                                        cout << "\nBooking Information\nNo bookings for " << day << "-" << month << "-" << year << "..\n";
                                }
                            }
                        }
                        else if(customerChoice.compare("3") == 0)
                        {
                            string customerAnswer;
                            cout << "\nToday's special deal:\nBuy 2 or more regular rooms (Single or double beds) with 1 special room and get 10% discount on each!!\n" <<
                            "If you want to take the deal enter 'y' or enter 'n'";
                            getline(cin, customerAnswer);
                            if(customerAnswer.compare("y") == 0)
                            {
                                int roomWanted;
                                cout << "Enter the number of rooms you want to book: ";
                                cin >> roomWanted;
                                for(int j=0;j<roomWanted;j++)
                                {
                                    string numOfRooms, floorChoice;
                                    int inDay, inMonth, inYear, outDay, outMonth, outYear, stayLength;
                                    cout << "\nBooking room " << (j+1) << " of " << roomWanted << " for you...\n\nPress 1 for single room, 2 for double room, 3 for special suite.\nEnter your choice: ";
                                    cin >> numOfRooms;
                                    cout << "What floor do you want to room on? 1,2 or 3 - Floor 2 is non-smoking\nEnter your choice: ";
                                    cin >> floorChoice;
                                    cout << "Enter check-in date\nEnter date (DD): ";
                                    cin >> inDay;
                                    cout << "Enter month (MM): ";
                                    cin >> inMonth;
                                    cout << "Enter year (YYYY): ";
                                    cin >> inYear;
                                    cout << "Enter check-out date\nEnter date (DD): ";
                                    cin >> outDay;
                                    cout << "Enter month (MM): ";
                                    cin >> outMonth;
                                    cout << "Enter year (YYYY): ";
                                    cin >> outYear;
                                    cout << "Enter the number of days of your (according to check-out day)\nEnter here: ";
                                    cin >> stayLength;
                                    cout << "Booked room " << (j+1) << " of " << roomWanted << " for you!!\n" << lines;
                                    ifstream input;
                                    input.open("bookings.txt");
                                    //input << "--------------------------\n" << floorChoice
                                }
                            }
                            //else if(customerAnswer.compare("n") == 0)
                        }
                    }
                    while(customerChoice.compare("4") != 0);
                }
            }
            if (correctName == 0)
                cout << "Invalid name or ID.\n";
        }
        else if(userChoice.compare("2")==0)
        {
            string name, username, address, phone, email, pID, ccNumber, ccDate, ccName;
            int month, day, year;
            cout << "Enter Your Name: ";
            getline(cin,name);
            cout << "Enter Your Username: ";
            getline(cin,username);
            cout << "Enter Your Address: ";
            getline(cin,address);string customerChoice;
            cout << "Enter Your Phone: ";
            getline(cin, phone);
            cout << "Enter Your Email: ";
            getline(cin, email);
            cout << "Enter Your Photo ID: ";
            getline(cin,pID);
            cout << "Enter Your Credit Card Number: ";
            getline(cin,ccNumber);
            cout << "Enter Your Credit Cards Expiration Date(DD-MM-YYYY): ";
            getline(cin,ccDate);
            cout << "Enter Your Credit Card Name: ";
            getline(cin,ccName);
            cout << "\nThank you for the information " << name << " !!\n\nYour account has been created..\nYou may now login and book rooms.";
            fstream newCustomer;
            newCustomer.open("customer.txt",fstream::app);
            newCustomer << "\n--------------------------\n" << name << endl << username << endl << address << endl
            << phone << endl << email << endl << pID << endl << ccNumber << endl << ccDate << endl << ccName;
            newCustomer.close();
            customer newCust(name, username, address, phone, email, pID, ccNumber, ccDate, ccName);
            custArray.push_back(newCust);
        }
        else if(userChoice.compare("3")==0)
        {
            int managerChoice;
            string managerUsername;
            string managerPassword;
            cout << "Username:";
            cin >> managerUsername;
            cout << "Password:";
            cin >> managerPassword;
            do
            {
                cout << "Hello manager" << hotelManager.managerName << " !!\n" << lines << "\n";
                cout << managerMenu;
                cin >> managerChoice;
                if(managerChoice == 1)
                {

                }
                else if(managerChoice == 2)
                {

                }
                else if(managerChoice == 3)
                {

                    //for(int i=0 hotel.allReservations.size();i++)
                    //{

                    //}
                }
                else if(managerChoice == 4)
                {

                }
                else if(managerChoice == 5)
                {

                }
                else if(managerChoice == 6)
                {

                }
                else if(managerChoice == 7)
                {

                }
                else if(managerChoice == 8)
                {

                }
                else if(managerChoice == 9)
                {
                    cout << lines << "\nCustomer Username\n" ;
                    for(int i=0;i<custArray.size();i++)
                    {
                        cout << custArray[i].customerUsername;
                    }
                     cout << "\n" <<lines;
                }
                else if(managerChoice == 10)
                {
                    for(int c=0;c<custArray.size();c++)
                    {
                        cout << lines << "\n name:" << custArray[c].nameofCustomer << endl
                             <<  "customer Username " << custArray[c].customerUsername << endl
                             << "address " << custArray[c].address << endl
                             << "phone num" << custArray[c].phoneNum << endl
                             << "email " << custArray[c].email_id << endl << lines;

                    }
                }
                else
                {
                    cout << "invalid option";
                }

            }while(hotelManager.managerUser.compare(managerUsername) == 0 && hotelManager.password.compare(managerPassword) == 0);

                cout << "Invalid name or password";

        }
        else
            cout << "Number is not an option. Please try again.";
    }
    while(userChoice.compare("4") != 0);
}
