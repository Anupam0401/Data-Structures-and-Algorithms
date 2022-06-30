/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        vector<int> secret_index(10,0);
        vector<int> guess_index(10,0);
        int bulls=0,cows=0;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]) cows++;
            secret_index[secret[i]-'0']++;
            guess_index[guess[i]-'0']++;
        }
        for(int i=0;i<10;i++){
            bulls+=min(secret_index[i],guess_index[i]);
        }
        bulls-=cows;
        string ans = to_string(cows)+"A"+to_string(bulls)+"B";
        return ans;
    }
};
// @lc code=end

