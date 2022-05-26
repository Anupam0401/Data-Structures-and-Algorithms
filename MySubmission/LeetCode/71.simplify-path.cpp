/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        path=path+"/";
        stack<string> store;
        string temp = "";
        for(int i=0;i<path.length();i++){
            if(path[i]!='/'){
                temp+=path[i];
            }
            else if(temp!=""){
                if(temp==".."){
                    if(!store.empty())  store.pop();
                    cout<<temp<<endl;
                    temp="";
                }
                else if(temp=="."){
                    temp="";
                }
                else{
                store.push(temp);
                temp = "";
                }
            }
            
        }
        string ans="";
        while(!store.empty()){
            ans="/"+store.top()+ans;
            store.pop();
        }
        if(ans=="")  ans="/";
        return ans;
    }
};
// @lc code=end

