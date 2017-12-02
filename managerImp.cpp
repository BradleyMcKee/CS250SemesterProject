//Bradley McKee
#include "manager.h"

using namespace std;

void manager::readMan(ifstream& in)
{
    in >> managerName
       >> managerUser
       >> password;
    in.close();
}
