/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)  return head;
        ListNode* dummy = head;
        while(dummy!=NULL){
            if(dummy->next!=NULL){
                ListNode* temp = dummy->next;   
                while(temp!=NULL && dummy->val == temp->val){
                    temp = temp->next;
                }
                dummy->next = temp;
            }
            dummy = dummy->next;
        }
        return head;
    }
};
// @lc code=end

