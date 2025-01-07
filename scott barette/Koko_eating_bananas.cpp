#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cmath>
using namespace std;

bool move_left(vector<int> &piles, int h, int target)
{
    int count = 0;

    for (auto &x : piles)
    {
        count += ceil(static_cast<double>(x) / target);
    }

    return (count <= h) ? true : false;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    sort(piles.begin(), piles.end());
    long long int low = 1;
    long long int high = piles[piles.size() - 1];
    long long int mid = 0;

    long long int remember = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (move_left(piles, h, mid)) // lessen the k
        {
            remember = mid;
            high = mid - 1;
        }
        else // more k
        {
            low = mid + 1;
        }
    }
    return remember;
}

void T_main()
{
    // conclusion: the more time you have, the less k you need
    // conclusion: the less time you have, the more k you need

    vector<int> p1{3, /*here*/ 6, 7, 11}; // 3 4 2 4  3 4 4 3
    int h1 = 8;
    assert(minEatingSpeed(p1, h1) == 4);

    vector<int> p5{3, 6, 7, 11}; // 3 6 6 1 6 5
    int h5 = 7;
    assert(minEatingSpeed(p5, h5) == 6);

    vector<int> p6{3, 6, 7, 11}; //  3 6 6 1 6 5
    int h6 = 6;
    assert(minEatingSpeed(p6, h6) == 6);

    vector<int> p7{3, 6, 7, 11}; //  3 6 7 7 4
    int h7 = 5;
    assert(minEatingSpeed(p7, h7) == 7);

    vector<int> p8{3, 6, 7, 11}; //  3 6 7 7 4
    int h8 = 4;
    assert(minEatingSpeed(p8, h8) == 11);

    // conclusion: when time is less than piles, the answer is the max element in the piles

    vector<int> p2{30, 11, 23, 4, 20}; // 30 11 23 4 20
    int h2 = 5;
    assert(minEatingSpeed(p2, h2) == 30);

    vector<int> p3{30, 11, 23, 4, 20}; // 23 7 11 23 4 20
    int h3 = 6;
    assert(minEatingSpeed(p3, h3) == 23);

    vector<int> p4{1, 2, 3};
    int h4 = 3;
    assert(minEatingSpeed(p4, h4) == 3);
}

void T_move_left()
{
    vector<int> p1{3, 6, 7, 11}; // 5 0 1 0 0 0
    int h1 = 8;
    int k1 = 7;
    assert(move_left(p1, h1, k1) == true);

    vector<int> p2{3, 6, 7, 11}; // 7 3 0 3 0 2 0 0
    int h2 = 8;
    int k2 = 4;
    assert(move_left(p2, h2, k2) == true);

    vector<int> p3{3, 6, 7, 11}; // 8 5 2 0 4 1 0 3 3
    int h3 = 8;
    int k3 = 3;
    assert(move_left(p3, h3, k3) == false);
}

int main()
{
    T_move_left();
    T_main();
}