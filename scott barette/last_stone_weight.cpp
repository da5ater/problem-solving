#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int lastStoneWeight(vector<int> &stones)
{
    while (!heap.empty())
    {
        if (heap.size() == 1)
            return heap.top();

        int x = heap.top();
        heap.pop();

        int y = heap.top();
        heap.pop();

        if (x < y)
        {
            y -= x;
            heap.push(y);
        }
        else if (x > y)
        {
            x -= y;
            heap.push(x);
        }
    }

    return 0;
}

int main()
{
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << lastStoneWeight(stones);
    return 0;
}