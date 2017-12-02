//Bradley McKee
#ifndef DATE_H
#define DATE_H

struct Date{
    Date(){};
    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    int day;
    int month;
    int year;
};

#endif // DATE_H
