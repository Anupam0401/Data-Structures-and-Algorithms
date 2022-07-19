/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    // naive, brute force approach
    // ListNode* rotateRight(ListNode* head, int k) {
    //     if(k==0 || !head || !head->next)  return head;
    //     while (k--)
    //     {
    //         ListNode *last = head;
    //         int valu = 0;
    //         while(last->next!=NULL){
    //             if(last->next->next==NULL){
    //                 valu = last->next->val;
    //                 last->next = NULL;
    //                 break;
    //             }
    //             last=last->next;
    //         }
    //         ListNode *newNode = new ListNode(valu);
    //         newNode->next = head;
    //         head = newNode;
    //         if(k==0)    return newNode;
    //     }
    //     return head;
    // }

    // optimised O(n) approach
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head || !head->next)  return head;
        int len = 1;
        ListNode *temp = head;
        while (temp->next!=NULL and ++len)
            temp=temp->next;
        temp->next = head;
        k = k%len;
        k = len-k;
        while(k--)  temp = temp->next;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};
// @lc code=end

