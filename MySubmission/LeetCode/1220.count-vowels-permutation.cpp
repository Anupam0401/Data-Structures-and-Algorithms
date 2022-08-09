/*
 * @lc app=leetcode id=1220 lang=cpp
 *
 * [1220] Count Vowels Permutation
 */

// @lc code=start
class Solution
{
private:
    const int MOD = 1e9 + 7;

public:
    // tabulation bottom up iterative approach
    // int countVowelPermutation(int n)
    // {
    //     long dp[5][n + 1], ans = 0;
    //     dp[0][1] = dp[1][1] = dp[2][1] = dp[3][1] = dp[4][1] = 1;
    //     for (int i = 2; i <= n; i++)
    //     {
    //         dp[0][i] = dp[1][i - 1];
    //         dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % MOD;
    //         dp[2][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[3][i - 1] + dp[4][i - 1]) % MOD;
    //         dp[3][i] = (dp[2][i - 1] + dp[4][i - 1]) % MOD;
    //         dp[4][i] = dp[0][i - 1];
    //     }
    //     for (int i = 0; i < 5; i++)
    //         ans = (ans + dp[i][n]) % MOD;
    //     return ans;
    // }

    // tabulation bottom up iterative space optimised
    int countVowelPermutation(int n)
    {
        long a, e, i, o, u, a_new, e_new, i_new, o_new, u_new;
        a = e = i = o = u = 1;
        for (int j = 2; j <= n; j++)
        {
            a_new = e;
            e_new = (a + i) % MOD;
            i_new = (a + e + o + u) % MOD;
            o_new = (i + u) % MOD;
            u_new = a;
            a = a_new;
            e = e_new;
            i = i_new;
            o = o_new;
            u = u_new;
        }
        return (a + e + i + o + u) % MOD;
    }

    // recursive approach -- TLE
    int recurse(int n, unordered_map<char, vector<char>> &mappings, char start)
    {
        if (n == 0)
            return 1;
        int ans = 0;
        for (auto vowel : mappings[start])
        {
            ans = (ans + recurse(n - 1, mappings, vowel)) % MOD;
        }
        return ans;
    }

    // memoization top down recusive approach
    int recurseMemo(int n, unordered_map<char, vector<char>> &mappings, char start, unordered_map<char, vector<int>> &dp)
    {
        if (n == 0)
            return 1;
        int ans = 0;
        if (dp[start][n] != -1)
            return dp[start][n];
        for (auto vowel : mappings[start])
        {
            ans = (ans + recurseMemo(n - 1, mappings, vowel, dp)) % MOD;
        }
        return dp[start][n] = ans;
    }
    // int countVowelPermutation(int n)
    // {
    //     unordered_map<char,vector<char>> mappings{{'s', {'a', 'e', 'i', 'o', 'u'}},
    //                                         {'a', {'e'}},
    //                                         {'e', {'a', 'i'}},
    //                                         {'i', {'a', 'e', 'o', 'u'}},
    //                                         {'o', {'i', 'u'}},
    //                                         {'u', {'a'}}};
    //     unordered_map<char,vector<int>> dp;
    //     dp['s'] = dp['a'] = dp['e'] = dp['i'] = dp['o'] = dp['u'] = vector<int>(n+1,-1);
    //     return recurseMemo(n,mappings,'s',dp);
    // }
};
// @lc code=end

// s - a,e,i,o,u
// a - e
// e - a, i
// i - a,e,o,u
// o - i,u
// u - a