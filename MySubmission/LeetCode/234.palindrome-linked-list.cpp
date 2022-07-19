/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // brute force, highly uneconomical approach
        vector<int> nums;
        ListNode* temp = head;
        while (temp!=NULL)
        {   
            nums.push_back(temp->val);
            temp = temp->next;
        }
        int n = nums.size();
        for(int i=0;i<=(n-1)/2;i++){
            if(nums[i]!=nums[n-1-i])    return false;
        }
        return true;
    }
};
// @lc code=end

