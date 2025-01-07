#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c, d;

    cin >> a >> b >> c >> d;

    double x;
    double y;

    y = d * log(c);
    x = b * log(a);

    if (x > y)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}