// Given a string s, the task is to check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

class Solution
{
public:
    int isRepeat(string s)
    {
        int n = s.length();
        unordered_set<char> set;
        for (int i = 0; i < n; i++)
        {
            if (set.find(s[i]) == set.end())
                set.insert(s[i]);
        }
        if (n % set.size() != 0)
            return 0;
        string str = "";
        // store the string formed from the unordered_set set in opposite order
        for (auto it = set.rbegin(); it != set.rend(); it++)
            str += *it;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != str[i % str.length()])
                return 0;
        }
        return 1;
    }
};