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

void swap(date &l, date &r)
{
    swap(l.year, r.year);
    swap(l.month, r.month);
    swap(l.day, r.day);
};

date represent(string date1)
{
    static date dt1;
    int year1 = stoi(date1.substr(0, 4));
    int month1 = stoi(date1.substr(5, 2));
    int day1 = stoi(date1.substr(8));

    dt1.year = year1;
    dt1.month = month1;
    dt1.day = day1;
    return dt1;
}

bool is_leap(int year)
{

    if (year % 100 == 0)
    {
        return (year % 400 == 0) ? true : false;
    }

    return (year % 4 == 0) ? true : false;
}

date next_month(date d)
{
    if (d.month == 12)
    {
        d.year++;
        d.month = 1;
        d.day = 1;
        return d;
    };
    d.month++;
    d.day = 1;
    return d;
}

date next_day(date d)
{
    std::unordered_map<int, int> nonLeapYearMonths = {
        {1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};

    // Define the map for leap years
    std::unordered_map<int, int> leapYearMonths = {
        {1, 31}, {2, 29}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};

    int curr_day = d.day;
    if (is_leap(d.year))
    {
        int month_count = leapYearMonths.at(d.month);
        curr_day++;
        if (curr_day > month_count)
        {
            return next_month(d);
        }
        else
        {
            d.day++;
            return d;
        }
    }
    else
    {
        int month_count = nonLeapYearMonths.at(d.month);
        curr_day++;
        if (curr_day > month_count)
        {
            return next_month(d);
        }
        else
        {
            d.day++;
            return d;
        }
    }
}

int daysBetweenDates(string date1, string date2)
{
    date dt1 = represent(date1);
    date dt2 = represent(date2);

    if (dt1 > dt2)
        swap(dt1, dt2);

    cout << dt1.day;
    int day = 0;

    while (dt2 > dt1)
    {
        dt1 = next_day(dt1);
        day++;
    }
    return day;
};

void test()
{
    assert(daysBetweenDates("2019-06-29", "2019-06-30") == 1);
    assert(daysBetweenDates("2020-01-15", "2019-12-31") == 15);
    assert(daysBetweenDates("2022-07-25", "2018-03-12") == 1596);
    assert(daysBetweenDates("2022-07-25", "2022-07-25") == 0);
}

// void test_swap()
// {
//     date d1{2019, 19, 9};
//     date d1{2020, 20, 20};

//     assert(swap())
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

// void t_isleap()
// {

//     assert(is_leap(1968) == true);
//     assert(is_leap(1971) == false);
//     assert(is_leap(2000) == true);
// }

void t_next_month()
{
    date d1 = date{2022, 1, 31};
    date ex1 = date{2022, 2, 1};
    assert(next_month(d1) == ex1);

    date d2 = date{2022, 12, 31};
    date ex2 = date{2023, 1, 1};
    assert(next_month(d2) == ex2);
}

int main()
{
    // string date1 = "2019-06-29";
    // string date2 = "2019-06-30";

    // string date3 = "2020-01-15";
    // string date4 = "2019-12-31";
    // daysBetweenDates(date3, date4);

    assert(daysBetweenDates("2019-06-29", "2019-06-30") == 1);
}