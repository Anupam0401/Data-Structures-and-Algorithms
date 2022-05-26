#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

// 3. Sandwiches with no wastage
// Given two integers breads and eggslice. The ingredients of different sandwiches are as follows:
// King sandwich: 4 breads and 1 eggslice
// Regular sandwich: 2 breads and 1 eggslice.
// Return [total_king, total_regular] so that the number of remaining breads equal to 0 and the number
// of remaining eggSlice equal to 0. If it is not possible to make the remaining and eggslice equal to 0
// return[] .

// Example 1:
// Input: breads = 16, eggslice 7
// Output: [1,6]
// Explanation: To make one King sandwich and 6 Regular sandwich: we need 4*1 +2*6 = 16 breads and
// 1+6=7 eEgSlice. There will be no remaining ingredients.

// Example 2:
// Input: breads = 17, eggslice = 4
// Output: 0
// Explanation: There will be no way to use all ingredients to make Regular and King sandwiches.

class Solution
{
public:
    vector<int> makeSandwiches(int breads, int eggSlice) {
        vector<int> ans;
        int k = 0, r = 0;
        while (breads >= 4)
        {
            k++;
            breads -= 4;
        }
        while (eggSlice >= 1)
        {
            r++;
            eggSlice -= 1;
        }
        ans.push_back(k);
        ans.push_back(r);
        // if it not possible to make breads and eggSlice equal to 0 then return []
        if (breads != 0 || eggSlice != 0)
            ans.clear();
        return ans;
    }
};