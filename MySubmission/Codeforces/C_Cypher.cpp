// Luca has a cypher made up of a sequence of n wheels, each with a digit ai written on it. On the i-th wheel, he made bi moves. Each move is one of two types:

// up move (denoted by U): it increases the i-th digit by 1. After applying the up move on 9, it becomes 0.
// down move (denoted by D): it decreases the i-th digit by 1. After applying the down move on 0, it becomes 9.
// Example for n=4. The current sequence is 0 0 0 0.
// Luca knows the final sequence of wheels and the moves for each wheel. Help him find the original sequence and crack the cypher.


#include <bits/stdc++.h>
#include <algorithm>
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int no_of_wheels;
        cin >> no_of_wheels;
        vector<int> final_wheels(no_of_wheels);
        for(int i=0;i<no_of_wheels;i++){
            cin >> final_wheels[i];
        }
        vector<pair<int, string>> moves(no_of_wheels);
        for(int i=0;i<no_of_wheels;i++){
            int x;
            cin>>x;
            string s;
            cin >> s; //U  and D represent an up move and a down move respectively
            moves[i].first = x;
            moves[i].second = s;
        }
        vector<int> current_wheels(no_of_wheels);
        for(int i=0;i<no_of_wheels;i++){
            current_wheels[i] = final_wheels[i];
        }
        int ans = 0;
        for(int i=0;i<no_of_wheels;i++){
            int x = moves[i].first;
            string s = moves[i].second;
            for(int j=x-1;j>=0;j--){
                if(s[j]=='D'){
                    if(current_wheels[i]==9){
                        current_wheels[i] = 0;
                    }
                    else{
                        current_wheels[i]++;
                    }
                }
                else{
                    if(current_wheels[i]==0){
                        current_wheels[i] = 9;
                    }
                    else{
                        current_wheels[i]--;
                    }
                }
            }
        }
        // output n space-separated digits  — the initial sequence of the cypher
        for(int i=0;i<no_of_wheels;i++){
            cout<<current_wheels[i]<<" ";
        }
        cout<<endl;
        
    }

    return 0;
}
