// You have a chat log of n messages. You are given two string arrays messages and senders where messages[i] is a message sent by senders[i].

// A message is list of words that are separated by a single space with no leading or trailing spaces. The word count of a sender is the total number of words sent by the sender. Note that a sender may send more than one message.

// Return the sender with the largest word count. If there is more than one sender with the largest word count, return the one with the lexicographically largest name.

// Note:

// - Uppercase letters come before lowercase letters in lexicographical order.
// - "Alice" and "alice" are distinct.


class Solution {
public:
    int wordSize(string sentence){
        //find the number of words in the sentence
        int count = 0;
        for(int i = 0; i < sentence.size(); i++){
            if(sentence[i] == ' '){
                count++;
            }
        }
        return count + 1;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> m;
        for (int i = 0; i < messages.size(); ++i) {
            m[senders[i]] += wordSize(messages[i]);
        }
        string res;
        int max_cnt = 0;
        for (auto& p : m) {
            if (p.second > max_cnt || (p.second == max_cnt && p.first > res)) {
                max_cnt = p.second;
                res = p.first;
            }
        }
        return res;
    }
};