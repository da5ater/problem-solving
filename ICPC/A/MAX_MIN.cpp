#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;

    cout << std::min({a, b, c}) << " " << std::max({a, b, c});
}