#include <iostream>
using namespace std;

int main()
{
    long long int n, year, month, day;

    cin >> n;

    year = (n - (n % 365)) / 365;
    month = ((n % 365) - ((n % 365) % 30)) / 30;
    day = ((n % 365) % 30);
    cout << year << " years\n";
    cout << month << " months\n";
    cout << day << " days\n";
}