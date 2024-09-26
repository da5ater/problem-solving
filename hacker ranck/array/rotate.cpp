#include <iostream>
#include <vector>
using namespace std;

vector<int> rotateLeft(int d, vector<int> arr)
{
    int n;
    cin >> d >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << d << n;
    for (int x : arr)
    {
        cout << x;
    }
}

int main()
{
    rotateLeft(4, )
}