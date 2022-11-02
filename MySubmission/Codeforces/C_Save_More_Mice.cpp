#include<bits/stdc++.h>
using namespace std;

// There are one cat, k mice, and one hole on a coordinate line. The cat is located at the point 0, the hole is located at the point n. All mice are located between the cat and the hole: the i-th mouse is located at the point xi (0<xi<n). At each point, many mice can be located.

// In one second, the following happens. First, exactly one mouse moves to the right by 1. If the mouse reaches the hole, it hides (i.e. the mouse will not any more move to any point and will not be eaten by the cat). Then (after that the mouse has finished its move) the cat moves to the right by 1. If at the new cat's position, some mice are located, the cat eats them (they will not be able to move after that). The actions are performed until any mouse hasn't been hidden or isn't eaten.

// In other words, the first move is made by a mouse. If the mouse has reached the hole, it's saved. Then the cat makes a move. The cat eats the mice located at the pointed the cat has reached (if the cat has reached the hole, it eats nobody).

// Each second, you can select a mouse that will make a move. What is the maximum number of mice that can reach the hole without being eaten?

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> positions(k);
        for(int i=0;i<k;i++){
            cin>>positions[i];
        }
        sort(positions.begin(),positions.end());
        int ans = 0;
        int cat = 0;
        for(int i=0;i<k;i++){
            if(positions[i] > cat){
                ans++;
                cat++;
            }
        }
        cout<<ans<<endl;
    }
}