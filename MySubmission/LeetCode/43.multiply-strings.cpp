/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.length();
        int l2 = num2.length();
        vector<vector<string>> res;
        int carry = 0;
        string zero = "";
        for(int i=l1-1;i>=0;i--){
            int n1 = num1[i]-'0';
            string str="";
            for(int j=l2-1;j>=0;j--){
                int n2 = num2[j]-'0';
                int temp = n1*n2+carry;
                carry = temp/10;
                str = to_string(temp%10)+str;
            }
            res.push(zero+str);
            zero+='0';
        }
        string ans = res[res.size()-1];
        carry = 0;
        for(int i=res.size()-2;i>=0;i--){
            l1 = ans.size(), l2 = res[i].size();
            for(int k=0;k<max(l1,l2);k++){
                int n1 = ans[k]-'0';
                if(k>=res[i].size()){
                    ans[k] = to_string((n1+carry)%10);
                    carry = (n1+carry)/10;
                }
                else{
                    int n2 = res[i][k]-'0';
                    ans[k] = to_string((n1+n2carry)%10);
                    carry = (n1+n2+carry)/10;
                }
            }
            if(carry)   ans.push_back(to_string(carry));
        }
        // reverse ans
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end

