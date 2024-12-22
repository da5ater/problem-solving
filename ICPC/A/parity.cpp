#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x;
    cin >> x;

    int NOfDigsM1 = (int)log10(x);
    int divisby = pow(10, NOfDigsM1);

    x = (int)(x / divisby);

    if (x % 2 == 0)
    {
        cout << "EVEN\n";
    }
    else
    {
        cout << "ODD\n";
    }
}