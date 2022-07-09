

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPrime(int n)
    {
        if (n == 1)
            return false;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }
    // 2 players A and B take turns alternatively to play a game in which they have N numbers on a paper. In one turn, a player can replace one of the numbers by any of its factor (except for 1 & the number itself). The player who is unable to make a move looses the game. Find the winner of the game if A starts the game and both play optimally.
    bool brainGame(vector<int>nums) {
        int n = nums.size();
        int primes = 0;
        int nonPrimes = 0;
        for (int i = 0; i < n; i++) {
            if (isPrime(nums[i])) {
                primes += nums[i];
            } else {
                nonPrimes += nums[i];
            }
        }
        return primes > nonPrimes;
    }
};