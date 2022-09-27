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
        while(x<n and y<n){
            while( y<n and s[y]=='.'){
                y++;
            }
            if(s[x]==s[y]){
                while(x<=y){
                    s[x++]=s[y];
                }
            }
            else if(s[x]=='R' and s[y]=='L'){
                int i = x, j = y;
                while(i<j){
                    s[i++]=s[x];
                    s[j--]=s[y];
                }
            }
            else if((s[x]=='.' and s[y]=='L')||(s[x]=='R' and s[y]=='.')){
                while(x<=y){
                    s[x++] = s[y];
                }
            }
            x = y;
            y++;
        }
        x = n-2;
        if(s[n-1]=='.'){
            while(x>=0 and s[x]=='.')   x--;
            if(x>=0 and s[x]=='R')   while(x<n) s[x++]='R';
        }
        return s;
    }
};
// @lc code=end

