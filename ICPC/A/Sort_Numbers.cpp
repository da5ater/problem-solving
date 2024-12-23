#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long int a, b, c;
    cin >> a >> b >> c;

    vector<int> res;

    res.push_back(a);
    res.push_back(b);
    res.push_back(c);

    sort(res.begin(), res.end(), [&](int aa, int bb)
         { return aa > bb; });

    cout << res[0] << endl;
    cout << res[1] << endl;
    cout << res[2] << endl;

    cout << endl;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}