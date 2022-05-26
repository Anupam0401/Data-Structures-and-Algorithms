// Given a string S on which you need to perform Q replace operations.
// Each replacement operation has 3 parameters: a starting index i, a source word x and a target word y. The rule is that if x starts at position i in the original string S, then we will replace that occurrence of x with y. If not, we do nothing.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

// class Solution {
//   public:
//     string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
//         for(int i=0;i<Q;i++){
//             if(sources[i]==S.substr(index[i],index[i]+sources[i].length())){
//                 S=S.substr(0,index[i]-1)+S.substr(index[i]+sources[i].length()+1);
//                 S.insert(index[i],sources[i]);
//             }
//         }
//         return S;
//     }
// };
class Solution
{
public:
    string findAndReplace(string S, int Q, int index[], string sources[], string targets[])
    {
        int addIndex = 0;
        for (int i = 0; i < Q; i++)
        {
            int start = index[i]+addIndex;
            string source = sources[i];
            string target = targets[i];
            int len = source.length();
            cout<<start<<" "<<len<<endl;
            if (S.substr(start, len) == source)
            {
                cout<<"IN"<<endl;
                S.replace(start, len, target);
                addIndex+=target.length()-len;
            }
        }
        return S;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends