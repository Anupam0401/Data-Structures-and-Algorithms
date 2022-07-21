/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left>=right) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr  = head;
        ListNode* pre = dummy;
        right -= left;
        while(--left){
            curr = curr->next;
            pre = pre->next;
        }
        ListNode *prev = pre;
        while(right-->=0){
            ListNode* temp= curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        pre->next->next = curr;
        pre->next = prev;
        return dummy->next;
    }
};
// @lc code=end

