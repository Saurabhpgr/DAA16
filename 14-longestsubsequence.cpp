#include <iostream>
#include <string>
using namespace std;

class LCS
{
private:
    string s1, s2;
    int dp[100][100];

public:
    void input()
    {
        while (true)
        {
            cout << "Enter first string: ";
            cin >> s1;

            if (s1.empty())
            {
                cout << "String cannot be empty!\n";
            }
            else
                break;
        }

        while (true)
        {
            cout << "Enter second string: ";
            cin >> s2;

            if (s2.empty())
            {
                cout << "String cannot be empty!\n";
            }
            else
                break;
        }
    }

    void longestSubsequence()
    {
        int m = s1.length();
        int n = s2.length();

        // Initialize first row and column
        for (int i = 0; i <= m; i++)
            dp[i][0] = 0;

        for (int j = 0; j <= n; j++)
            dp[0][j] = 0;

        // Fill DP table
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    if (dp[i - 1][j] > dp[i][j - 1])
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = dp[i][j - 1];
                }
            }
        }

        cout << "\nLength of Longest Common Subsequence = "
             << dp[m][n] << endl;
    }
};

int main()
{
    LCS obj;

    obj.input();

    obj.longestSubsequence();

    return 0;
}