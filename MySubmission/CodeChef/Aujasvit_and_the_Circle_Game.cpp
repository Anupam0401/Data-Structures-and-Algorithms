#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define lli long long int
using namespace std;
void solve(lli m, lli x);
// N  people stand in a circle, each assigned an index from 1 to N in clockwise order. Then the following operation is done N−1 times.

// The person with the lowest index holds a coin.
// The coin then moves to the next person clockwise M−1 times.
// The person who is holding the coin is removed from the circle.

// The last person remaining after N−1 operations is the winner.

// Aujasvit has already decided on the integer M to be used in the game. Before inviting people to play his game, Aujasvit wants to know the winner if the game has 1 player, 2 players, 3 players, …, X players.

// output X integers A1,A2,…,AX, where Ai is the index of the winner if i people are playing this game.

void solve(lli m, lli x)
{
    lli a[x];
    a[0] = 1;
    for (lli i = 1; i < x; i++)
    {
        a[i] = (a[i - 1] + m - 1) % i + 1;
    }
    for (lli i = 0; i < x; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        lli m, x;
        cin >> m >> x;
        solve(m, x);
    }
    return 0;
}