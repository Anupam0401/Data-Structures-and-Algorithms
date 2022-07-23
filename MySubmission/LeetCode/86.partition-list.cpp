/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
class Solution
{
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = new ListNode(0);
        ListNode *right = new ListNode(0);
        ListNode *left_tail = left;
        ListNode *right_tail = right;
        while (head != NULL)
        {
            if (head->val < x)
            {
                left_tail->next = head;
                left_tail = left_tail->next;
            }
            else
            {
                right_tail->next = head;
                right_tail = right_tail->next;
            }
            head = head->next;
        }
        right_tail->next=NULL;
        left_tail->next = right->next;
        return left->next;
    }
};
// @lc code=end
