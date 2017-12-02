//Bradley McKee
#include "customer.h"

using namespace std;
//FUNCTIONS IMPLEMENTATIONS FOR EVERYTHING DEALING THE CUSTOMER

void customer::read(ifstream& in)
{
    string firstline, addressline, user;
    char trash;
    getline(in, firstline);
    nameofCustomer = firstline;
    getline(in,user);
    customerUsername = user;
    getline(in,addressline);
    address = addressline;
    in  >> phoneNum >> email_id >> uniqueID >> cardNum
    >> expiration.day >> trash >> expiration.month >> trash
    >> expiration.year >> typecard;

}
