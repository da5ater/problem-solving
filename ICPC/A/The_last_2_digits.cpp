#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    long long int a, b, c, d;

    cin >> a >> b >> c >> d;

    long long int result = (a % 100) % 100;
    result = (result * (c % 100)) % 100;
    result = (result * (b % 100)) % 100;
    result = (result * (d % 100)) % 100;

    (result <= 9) ? cout << setw(2) << setfill('0') << result : cout << result;
}