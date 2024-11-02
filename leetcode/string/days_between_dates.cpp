#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>
using namespace std;

struct date
{
public:
    int year;
    int month;
    int day;
    date() = default;
    date(int y, int m, int d) : year{y}, month{m}, day{d} {};

    friend bool operator>(const date &l, const date &r)
    {
        return std::tie(l.year, l.month, l.day) > std::tie(r.year, r.month, r.day);
    };
    friend bool operator==(const date &l, const date &r)
    {
        return std::tie(l.year, l.month, l.day) == std::tie(r.year, r.month, r.day);
    };

    date &operator=(const date &r)
    {
        year = r.year;
        month = r.month;
        day = r.day;
        return *this;
    };
};

static date dt1;
static date dt2;

void swap(date &l, date &r)
{
    swap(l.year, r.year);
    swap(l.month, r.month);
    swap(l.month, r.month);
};

void represent(string date1, string date2)
{
    int year1 = stoi(date1.substr(0, 4));
    int year2 = stoi(date2.substr(0, 4));
    int month1 = stoi(date1.substr(5, 2));
    int month2 = stoi(date2.substr(5, 2));
    int day1 = stoi(date1.substr(8));
    int day2 = stoi(date2.substr(8));

    dt1.year = year1;
    dt1.month = month1;
    dt1.day = day1;

    dt2.year = year2;
    dt2.month = month2;
    dt2.day = day2;

    if (dt1 > dt2)
        swap(dt1, dt2);
}

date next_day(date d)
{
    // bool is_leap(d.year);
    // int days_of_month(d.year, d.month);
    date temp{1, 1, 1};
    return temp;
}

void daysBetweenDates(string date1, string date2)
{
    represent(date1, date2);
    cout << dt1.day;
    int day = 0;

    while (dt2 > dt1)
    {
        dt1 = next_day(dt1);
        day++;
    }
};

// void test()
// {
//     assert(daysBetweenDates("2019-06-29", "2019-06-30") == 1);
//     assert(daysBetweenDates("2020-01-15", "2019-12-31") == 15);
//     assert(daysBetweenDates("2022-07-25", "2018-03-12") == 15);
// }

void t_next_day()
{
    // NON-leap
    date d1 = date{2022, 1, 1};
    date expected1 = date{2022, 1, 2};
    assert(next_day(d1) == expected1);

    date d2 = date{2022, 1, 31};
    date expected2 = date{2022, 2, 1};
    assert(next_day(d2) == expected2);

    date d3 = date{2022, 12, 31};
    date expected3 = date{2023, 1, 1};
    assert(next_day(d3) == expected3);

    // leaps
    date d4 = date{2022, 2, 29};
    date expected4 = date{2022, 3, 1};
    assert(next_day(d4) == expected4);
};

int main()
{
    // string date1 = "2019-06-29";
    // string date2 = "2019-06-30";

    // string date3 = "2020-01-15";
    // string date4 = "2019-12-31";
    // daysBetweenDates(date3, date4);

    t_next_day();
}