// You are given two strings s and sub. You are also given a 2D character array mappings where mappings[i] = [oldi, newi] indicates that you may replace any number of oldi characters of sub with newi. Each character in sub cannot be replaced more than once.

// Return true if it is possible to make sub a substring of s by replacing zero or more characters according to mappings. Otherwise, return false.

// A substring is a contiguous non-empty sequence of characters within a string.

class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int n=s.length();
        int m=sub.length();
        int mp=mappings.size();
        vector<vector<char>> alternateSub(m,vector<char>());
        for(int i=0;i<m;i++){
            alternateSub[i].push_back(sub[i]);
            for(int j=0;j<mp;j++){
                if(sub[i]==mappings[j][0]){
                    alternateSub[i].push_back(mappings[j][1]);
                }
            }
        }
        //print alternateSub
        for(int i=0;i<m;i++){
            for(int j=0;j<alternateSub[i].size();j++){
                cout<<alternateSub[i][j];
            }
            cout<<endl;
        }
        //check the whole alternateSub against each character of s
        bool ans=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i]==alternateSub[j][0]){
                    for(int k=1;k<alternateSub[j].size();k++){
                        if(i+k>=n||s[i+k]!=alternateSub[j][k]){
                            ans= false;
                            break;
                        }
                        else ans=true;
                    }
                }
            }
            if(ans) break;
        }
        return ans;
    }
};
