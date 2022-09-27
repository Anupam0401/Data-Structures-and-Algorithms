/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */

// @lc code=start
class Solution {
public:
    string pushDominoes(string s) {
        int n = s.length();
        if(n<=1)    return s;

        int x = 0,y = 1;
        while(x<n and y<n){ // move the right pointer y till we find a non '.' character
            while( y<n and s[y]=='.'){
                y++;
            }
            if(y==n and s[n-1]=='.'){ // if the right pointer goes beyond limit, we bring it back in case the element was '.'
                y=n-1;
            }
            if(s[x]==s[y]){ // both are same, so we can fill the entire range with the same character
                while(x<=y){
                    s[x++]=s[y];
                }
            }
            else if(s[x]=='R' and s[y]=='L'){ // both are different, so we need to fill the range with characters in between according to their nearness
                int i = x, j = y;
                while(i<j){
                    s[i++]=s[x];
                    s[j--]=s[y];
                }
            }
            else if((s[x]=='.' and s[y]=='L')){ // if the left pointer is '.' and right pointer is 'L', we fill the range with 'L'
                while(x<=y){
                    s[x++] = 'L';
                }
            }
            else if(s[x]=='R' and s[y]=='.'){ // if the left pointer is 'R' and right pointer is '.', we fill the range with 'R'
                while(x<=y){
                    s[x++] = 'R';
                }
            }
            x = y; // move the left pointer to the right pointer
            y++;  // move the right pointer to the next element
        }
        return s;
    }
};
// @lc code=end

