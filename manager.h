//Bradley McKee
#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <fstream>
#include "hotel.h"


struct manager{
    std::string managerName;
    std::string managerUser;
    std::string password;

    void readMan(std::ifstream& in);
};

#endif // MANAGER_H
