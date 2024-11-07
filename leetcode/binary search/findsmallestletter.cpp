#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int check_duplicates(vector<char> &lettters, int mid, int size)
{
    while (mid < size && lettters[mid] == lettters[mid + 1])
        ++mid;

    return (mid == size) ? 0 : mid + 1;
}

char nextGreatestLetter(vector<char> &letters, char target)
{
    if (target == 'z')
        return letters[0];

    int low = 0;
    int high = letters.size();
    int mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        char guess = letters[mid];

        if (guess == target)
        {
            if (mid == letters.size() - 1)
                return letters[0];

            return letters[check_duplicates(letters, mid, letters.size() - 1)];
        }
        if (guess < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (mid < 0 || mid >= letters.size())
    {
        return letters[0];
    }
    else if (letters[mid] < target)
    {
        return letters[mid + 1];
    }
    else
    {
        return letters[mid];
    }
};

void t_main()
{

    vector<char> vec1 = {'c',
                         'f',
                         'j'};
    char target1 = 'a';
    char expec1 = 'c';
    assert(nextGreatestLetter(vec1, target1) == expec1);

    vector<char> vec2 = {'c',
                         'f',
                         'j'};
    char target2 = 'c';
    char expec2 = 'f';
    assert(nextGreatestLetter(vec2, target2) == expec2);

    vector<char> vec3 = {'x',
                         'x',
                         'y', 'y'};
    char target3 = 'z';
    char expec3 = 'x';
    assert(nextGreatestLetter(vec3, target3) == expec3);

    vector<char> vec4 = {'x',
                         'x',
                         'y', 'y'};
    char target4 = 'y';
    char expec4 = 'x';
    assert(nextGreatestLetter(vec4, target4) == expec4);

    vector<char> vec5 = {'x',
                         'y',
                         'z'};
    char target5 = 'y';
    char expec5 = 'z';
    assert(nextGreatestLetter(vec5, target5) == expec5);

    vector<char> vec6 = {'a', 'b', 'x',
                         'y',
                         'z'};
    char target6 = 'e';
    char expec6 = 'x';
    assert(nextGreatestLetter(vec6, target6) == expec6);

    vector<char> vec7 = {'a', 'b', 'c', 'd', 'f', 'x',
                         'y',
                         'z'};
    char target7 = 'e';
    char expec7 = 'f';
    assert(nextGreatestLetter(vec7, target7) == expec7);

    vector<char> vec8 = {'c',
                         'f',
                         'j'};
    char target8 = 'k';
    char expec8 = 'c';
    assert(nextGreatestLetter(vec8, target8) == expec8);

    vector<char> vec9 = {'c',
                         'f',
                         'j'};
    char target9 = 'd';
    char expec9 = 'f';
    assert(nextGreatestLetter(vec9, target9) == expec9);

    vector<char> vec10 = {'e',
                          'e',
                          'g', 'g'};
    char target10 = 'g';
    char expec10 = 'e';
    assert(nextGreatestLetter(vec10, target10) == expec10);
}

void t_dup()
{

    vector<char> v1 = {'a', 'a', 'c'};
    int mid1 = 0;
    int expec1 = 2;
    assert(check_duplicates(v1, mid1, v1.size()) == expec1);

    vector<char> v2 = {'a', 'a', 'a'};
    int mid2 = 0;
    int expec2 = 0;
    assert(check_duplicates(v2, mid2, v2.size() - 1) == expec2);

    vector<char> v3 = {'a', 'b', 'c'};
    int mid3 = 0;
    int expec3 = 1;
    assert(check_duplicates(v3, mid3, v3.size() - 1) == expec3);
}

int main()
{
    t_main();
}