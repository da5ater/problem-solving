#include <iostream>

using namespace std;

void Simple_Calculator(long long int x, long long int y)
{
    cout << x << " + " << y << " = " << x + y << endl;
    cout << x << " * " << y << " = " << x * y << endl;
    cout << x << " - " << y << " = " << x - y << endl;
}
int main()
{
    long long int x, y;
    cin >> x >> y;

    Simple_Calculator(x, y);
}