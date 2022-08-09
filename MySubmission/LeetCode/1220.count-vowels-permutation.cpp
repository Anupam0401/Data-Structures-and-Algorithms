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
    // int countVowelPermutation(int n)
    // {
    //     const int MOD = 1e9 + 7;
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

    //recursive approach -- TLE
    int recurse(int n,unordered_map<char,vector<char>>& mappings,char start){
        if(n==0)    return 1;
        int ans = 0;
        for(auto vowel: mappings[start]){
            ans += recurse(n-1,mappings,vowel);
        }
        return ans;
    }
    int countVowelPermutation(int n)
    {
        unordered_map<char,vector<char>> mappings{{'s', {'a', 'e', 'i', 'o', 'u'}},
                                            {'a', {'e'}},
                                            {'e', {'a', 'i'}},
                                            {'i', {'a', 'e', 'o', 'u'}},
                                            {'o', {'i', 'u'}},
                                            {'u', {'a'}}};
        return recurse(n,mappings,'s');
    }
};
// @lc code=end

// s - a,e,i,o,u
// a - e
// e - a, i
// i - a,e,o,u
// o - i,u
// u - a