#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    double n;
    cin >> n;

    if (typeid(n) == typeid(float))
    {
        cout << "float " << (int)n << " " << n - (int)n << endl;
    }
}