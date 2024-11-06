#include <iostream>
#include <vector>

using namespace std;

int bs(vector<int> &x, int number)
{

    int low = 0;
    int high = x.size() - 1;
    int mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        int guess = x[mid];
        if (guess == number)
        {
            return mid;
        }
        else if (guess < number)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
};

int main()
{
    vector<int> x = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = 8;

    cout << bs(x, n);
}