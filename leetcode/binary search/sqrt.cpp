#include <iostream>
#include <math.h>
using namespace std;

int mySqrt(int x)
{
    int l = 0;
    int h = pow(2, 31) - 1;
    int mid = 0;
    int guess = 0;
    int index = 0;
    while (l <= h)
    {

        mid = l + (h - l) / 2;
        guess = mid * mid;

        if (guess > x)
        {
            index = mid;
            h = mid - 1;
        }
        else if (guess < x)
        {
            l = mid + 1;
        }
        else if (guess == x)
        {
            return mid;
        }
    }
    return index;
};

int main()
{
}