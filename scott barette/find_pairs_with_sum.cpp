#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class FindSumPairs
{
public:
    unordered_map<int, int> set1;
    unordered_map<int, int> set2;
    vector<int> vec1;
    vector<int> vec2;
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        vec1 = nums1;
        vec2 = nums2;

        for (auto &x : vec1)
        {
            set1[x]++;
        }

        for (auto &x : vec2)
        {
            set2[x]++;
        }
    };

    void add(int index, int val)
    {
        int temp = vec2[index];
        vec2[index] += val;
        set2[temp]--;
        set2[vec2[index]]++;
    }

    int count(int tot)
    {
        int count = 0;
        int number;
        for (auto k : set1)
        {
            number = tot - k.first;
            if (set2.find(number) != set2.end())
            {
                count += set2[number] * k.second;
            }
        }

        return count;
    }
};

int main()
{
    vector<int> nums1{1, 1, 2, 2, 2, 3};
    vector<int> nums2{1, 4, 5, 2, 5, 4};

    FindSumPairs *obj = new FindSumPairs(nums1, nums2);
    int c = obj->count(7);
    obj->add(3, 2);
    obj->add(0, 1);
    obj->add(1, 1);
    c = obj->count(7);
    cout << c;
}