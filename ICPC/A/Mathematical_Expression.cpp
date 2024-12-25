#include <iostream>

using namespace std;

int main()
{
    int a, b;
    long long c;
    char s;
    char q;

    cin >> a >> s >> b >> q >> c;

    switch (s)
    {
    case '+':
        (a + b == c) ? cout << "Yes\n" : cout << a + b << endl;
        break;
    case '*':
        (a * b == c) ? cout << "Yes\n" : cout << a * b << endl;
        break;
    case '-':
        (a - b == c) ? cout << "Yes\n" : cout << a - b << endl;
        break;

    default:
        break;
    }
}