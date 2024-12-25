#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    double n;
    cin >> n;

    float x = n - (int)n;

    if (x == 0)
    {
        cout << "int " << n << endl;
    }
    else
    {

        cout << "float " << (int)n << " " << x << endl;
    }
}