/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1 || !head)
            return head;
        ListNode *dummy = new ListNode(0);
        int count = 0;
        dummy->next = head;
        ListNode *cur = dummy, *pre = dummy, *nex = dummy;
        while (cur->next != nullptr)
        {
            count++;
            cur = cur->next;
        }
        while (count >= k)
        {
            cur = pre->next;
            nex = cur->next;
            for (int i = 1; i < k; i++)
            {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            count -= k;
        }
        return dummy->next;
    }
};
// @lc code=end
