// You are given a binary string s. In one second, all occurrences of "01" are simultaneously replaced with "10". This process repeats until no occurrences of "01" exist.

// Return the number of seconds needed to complete this process.

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                cnt++;
        }
        return cnt;
    }
};