#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b;

    cin >> a >> b;

    double x = a / b;
    double y = b / a;

    if (x - floor(x) == 0)
    {

        cout << "Multiples\n";
    }
    else if (y - floor(y) == 0)
    {
        cout << "Multiples\n";
    }
    else
    {
        cout << "No Multiples\n";
    }
}