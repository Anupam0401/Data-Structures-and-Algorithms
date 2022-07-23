// You are given an integer array rolls of length n and an integer k. You roll a k sided dice numbered from 1 to k, n times, where the result of the ith roll is rolls[i].

// Return the length of the shortest sequence of rolls that cannot be taken from rolls.

// A sequence of rolls of length len is the result of rolling a k sided dice len times.

// Note that the sequence taken does not have to be consecutive as long as it is in order.

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        set<int> S;
        for (int x : rolls)
            S.insert(x);
        int n = rolls.size();
        int ans = n;
        for (int i = 1; i <= k; i++)
        {
            if (S.find(i) == S.end())
            {
                ans = min(ans, shortestSequence(rolls, i));
            }
        }
        return ans;
    }
};
