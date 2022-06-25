// You are given a string s, where every two consecutive vertical bars '|' are grouped into a pair. In other words, the 1st and 2nd '|' make a pair, the 3rd and 4th '|' make a pair, and so forth.

// Return the number of '*' in s, excluding the '*' between each pair of '|'.

// Note that each '|' will belong to exactly one pair.

class Solution {
public:
    int countAsterisks(string s) {
        int countBars = 0 , ans=0;
        int l = s.length();
        for(int i=0;i<l;i++)
        {
            if(s[i]=='|')
            {
                countBars++;
            }
            if(countBars%2==0 && s[i]=='*')
            {
                ans++;
            }
        }
        return ans;
    }
};