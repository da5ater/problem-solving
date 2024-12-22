#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

// Function to find the character with the maximum frequency in the range [L, R]
char findMaxFrequencyChar(const string &str, int L, int R)
{
    // Your implementation here
    return ' '; // Placeholder
}

// Test cases
void runTests()
{
    // Basic test cases
    string str1 = "geekss";
    assert(findMaxFrequencyChar(str1, 0, 2) == 'e'); // 'e' appears twice
    assert(findMaxFrequencyChar(str1, 3, 5) == 's'); // 's' appears twice

    string str2 = "striver";
    assert(findMaxFrequencyChar(str2, 0, 1) == 's'); // 's' appears once, lexicographically smallest
    assert(findMaxFrequencyChar(str2, 1, 6) == 'r'); // 'r' appears twice
    assert(findMaxFrequencyChar(str2, 5, 6) == 'e'); // 'e' appears once

    // Edge cases
    string str3 = "a";
    assert(findMaxFrequencyChar(str3, 0, 0) == 'a'); // Single character
    string str4 = "aaaaa";
    assert(findMaxFrequencyChar(str4, 0, 4) == 'a'); // All characters the same

    // Lexicographical tie-breaking
    string str5 = "bacab";
    assert(findMaxFrequencyChar(str5, 0, 4) == 'a'); // 'a' and 'b' appear twice, 'a' is smaller
    assert(findMaxFrequencyChar(str5, 1, 3) == 'a'); // 'a' appears twice, 'c' once

    // Full range
    string str6 = "abcdefghijklmnopqrstuvwxyz";
    assert(findMaxFrequencyChar(str6, 0, 25) == 'a'); // All characters unique, smallest lexicographically

    // Large range with repetition
    string str7 = "abcabcabcabcabcabc";
    assert(findMaxFrequencyChar(str7, 0, 17) == 'a'); // 'a', 'b', 'c' appear 6 times each, 'a' smallest
    assert(findMaxFrequencyChar(str7, 2, 8) == 'c');  // 'c' appears twice, others once

    // Queries on smaller subranges
    string str8 = "mississippi";
    assert(findMaxFrequencyChar(str8, 0, 4) == 'i');  // 'i' appears twice
    assert(findMaxFrequencyChar(str8, 5, 10) == 'i'); // 'i' appears 3 times
    assert(findMaxFrequencyChar(str8, 0, 10) == 'i'); // 'i' appears 4 times

    // Complex patterns
    string str9 = "ababcbacadefegdehijhklij";
    assert(findMaxFrequencyChar(str9, 0, 8) == 'a');  // 'a' appears 4 times
    assert(findMaxFrequencyChar(str9, 9, 23) == 'e'); // 'e' appears 3 times

    // Edge case with empty range
    string str10 = "abcde";
    assert(findMaxFrequencyChar(str10, 2, 2) == 'c'); // Single character in range

    cout << "All test cases passed!" << endl;
}

int main()
{
    runTests();
    return 0;
}
