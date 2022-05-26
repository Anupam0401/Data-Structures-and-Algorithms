#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define lli long long int
using namespace std;

// The knight is standing in front of a long and narrow hallway. A princess is waiting at the end of it.

// In a hallway there are three doors: a red door, a green door and a blue door. The doors are placed one after another, however, possibly in a different order. To proceed to the next door, the knight must first open the door before.

// Each door can be only opened with a key of the corresponding color. So three keys: a red key, a green key and a blue key — are also placed somewhere in the hallway. To open the door, the knight should first pick up the key of its color.

// The knight has a map of the hallway. It can be transcribed as a string, consisting of six characters:

// R, G, B — denoting red, green and blue doors, respectively;
// r, g, b — denoting red, green and blue keys, respectively.
// Each of these six characters appears in the string exactly once.

// The knight is standing at the beginning of the hallway — on the left on the map.

// Given a map of the hallway, determine if the knight can open all doors and meet the princess at the end of the hallway.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<char> a;
        int r=0,b=0,g=0;
        for(int i = 0; i < 6; i++)
        {    
            char t;
            cin >> t;
            if(t == 'r')
                r=i;
            else if(t == 'g')
                g=i;
            else if(t == 'b')
                b=i;
            a.push_back(t);
        }

        for(int i = 0; i < 6; i++){
            if(a[i]=='R' && r>i)
            {    
                cout<<"NO"<<endl;
                break;
            }
            else if(a[i]=='G' && g>i)
            {
                cout<<"NO"<<endl;
                break;
            }
            else if(a[i]=='B' && b>i)
            {
                cout<<"NO"<<endl;
                break;
            }
            else if(i==5)
                cout<<"YES"<<endl;
        }
    }
    return 0;
}