#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    char c;
    cin >> c;

    if (isupper(c) == 0)
    {
        cout << char(toupper(c)) << endl;
    }
    else
    {
        cout << char(tolower(c)) << endl;
    }
}