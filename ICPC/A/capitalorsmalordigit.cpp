#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    char a;
    cin >> a;

    if (isalpha(a) == 0)
    {
        cout << "IS DIGIT\n";
    }
    else
    {
        cout << "ALPHA\n";
        (isupper(a) == 0) ? cout << "IS SMALL\n" : cout << "IS CAPITAL\n";
    }
}