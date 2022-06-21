/*
 * @lc app=leetcode id=1642 lang=cpp
 *
 * [1642] Furthest Building You Can Reach
 */

// You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.

// You start your journey from building 0 and move to the next building by possibly using bricks or ladders.

// While moving from building i to building i+1 (0-indexed),

// If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
// If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
// Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.

// @lc code=start
class Solution
{
public:
    int furthestBuilding(vector<int> &H, int bricks, int ladders)
    {
        int i = 0, n = size(H), jumpHeight;
        // pq will store the first ladder number of largest jumps
        priority_queue<int, vector<int>, greater<int>> pq;
        // first ladder number of jumps would be assumed to be the largest
        // hence, push all these jumps into the queue
        while (i < n - 1 && size(pq) < ladders)
        {
            jumpHeight = H[i + 1] - H[i];
            if (jumpHeight > 0)
                pq.push(jumpHeight);
            i++;
        }
        // From here, we can't just use ladder and need to spend bricks from now on...
        while (i < n - 1)
        {
            jumpHeight = H[i + 1] - H[i];
            // if next building is bigger than current, bricks need to be used
            if (jumpHeight > 0)
            {
                // First check if we have a previous jump requiring less number of bricks than currentDiff
                if (!pq.empty() && pq.top() < jumpHeight)
                {
                    // if there is, just use bricks for that jump and assign ladder for current one
                    bricks -= pq.top();
                    pq.pop();
                    pq.push(jumpHeight);
                }
                // jumpHeight is already minimum jump size. So, no choice than spending that many bricks
                else
                    bricks -= jumpHeight;
            }
            // if bricks become negative, we can't travel any further as all bricks and ladders are used up
            if (bricks < 0)
                return i;
            i++;
        }
        return i;
    }
};
// @lc code=end
