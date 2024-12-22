#include <iostream>

using namespace std;

int main()
{
    long long int n, m;
    cin >> n >> m;

    int x = n % 10;
    int y = m % 10;

    cout << n + m;
}