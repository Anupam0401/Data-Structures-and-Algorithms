string Solution::solve(string A) {
    stack<char> s;
    string ans;
    for(int i=0;i<A.length();i++){
        if(A[i]>='a' && A[i]<='z'){
            ans+=A[i];
        }
        else if(A[i]=='('){
            s.push(A[i]);
        }
        else if(A[i]==')'){
            while(!s.empty() && s.top()!='('){
                ans+=s.top();
                s.pop();
            }
            if(!s.empty()) s.pop();
        }
        else{
            while(!s.empty() && pres(s.top())>pres(A[i])){
                ans+=s.top();
                s.pop();
            }
            s.push(A[i]);
        }
    }
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    return ans;
}