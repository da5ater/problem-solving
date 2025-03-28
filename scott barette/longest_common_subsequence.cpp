#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

    for (int i = text1.size() - 1; i >= 0; i--)
    {
        for (int j = text2.size() - 1; j >= 0; j--)
        {

            if (text1[i] == text2[j])
            {

                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    return dp[0][0];
}

int main()
{
    // Test case 1 // 3
    cout << "Test 1: " << longestCommonSubsequence("abcde", "ace") << endl;

    // Test case 2 // 3
    cout << "Test 2: " << longestCommonSubsequence("abc", "abc") << endl;

    // Test case 3 // 0
    cout << "Test 3: " << longestCommonSubsequence("abc", "def") << endl;
}