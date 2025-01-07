#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    long double x, p;
    cin >> x >> p;

    long double original;

    original = p / (1 - (x / 100));

    cout << setprecision(2) << std::fixed;
    cout << original;
}