#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int arr[6][6]{
        {9, 9, 9, 1, 1, 1},
        {0, 9, 0, 4, 3, 2},
        {9, 9, 9, 1, 2, 3},
        {0, 0, 8, 6, 6, 0},
        {0, 0, 0, 2, 0, 0},
        {0, 0, 1, 2, 4, 0}};

    vector<int> collection;
    int sum = 0;

    for (int i = 1; i < 5; i++)
    {
        for (int j = 1; j < 5; j++)
        {
            sum += arr[i - 1][j - 1];
            sum += arr[i - 1][j];
            sum += arr[i - 1][j + 1];
            sum += arr[i][j];
            sum += arr[i + 1][j - 1];
            sum += arr[i + 1][j];
            sum += arr[i + 1][j + 1];
            collection.push_back(sum);
            sum = 0;
        }
    }
    for (auto &&i : collection)
    {
        cout << i << " ";
    }

    cout << *max_element(collection.begin(), collection.end());
}