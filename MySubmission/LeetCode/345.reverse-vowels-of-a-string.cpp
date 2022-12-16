/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        string vow = "";
        int n = s.length();
        for(int i=0;i<n;i++){
            char ch = tolower(s[i]);
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                vow+=s[i];
            }
        }
        reverse(vow.begin(),vow.end());
        int j=0;
        for(int i=0;i<n;i++){
            char ch = tolower(s[i]);
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                s[i]=vow[j++];
            }
        }
        return s;
    }
};
// @lc code=end

