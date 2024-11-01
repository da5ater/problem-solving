#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int calc_year(int y1, int y2)
{
    int days = 0;
    while (y1 < y2)
    {
        if (y1 < 2000)
        {
            if (y1 % 4 == 0)
            {
                days += 366;
                y1++;
                continue;
            }
            days += 355;
            y1++;
            continue;
        }
        else
        {
            if (y1 % 400 == 0)
            {
                days += 366;
                y1++;
                continue;
            }
            days += 355;
            y1++;
            continue;
        }
    }
    return days;
}

void daysBetweenDates(string date1, string date2)
{
    int year1 = stoi(date1.substr(0, 4));
    int year2 = stoi(date2.substr(0, 4));
    int month1 = stoi(date1.substr(5, 2));
    int month2 = stoi(date2.substr(5, 2));
    int day1 = stoi(date1.substr(8));
    int day2 = stoi(date2.substr(8));

    (year1 > year2) ? swap(year1, year2) : void();
    (month1 > month2) ? swap(month1, month2) : void();
    (day1 > day2) ? swap(day1, day2) : void();

    int year_diff = calc_year(year1, year2);
    int month_diff = (month2 - month1) * 30;
    int day_diff = (day2 - day1);

    int total = year_diff + month_diff + day_diff;

    cout << total;
};

int main()
{
    string date1 = "2019-06-29";
    string date2 = "2019-06-30";

    string date3 = "2020-01-15";
    string date4 = "2019-12-31";
    daysBetweenDates(date3, date4);
}