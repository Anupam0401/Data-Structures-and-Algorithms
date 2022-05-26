/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(-1,nullptr);
        ListNode* dummy = ans;
        while(list1 && list2){
            if(list1->val<list2->val){
                ans->next = list1;
                list1=list1->next;
            }
            else{
                ans->next=list2;
                list2=list2->next;
            }
            ans=ans->next;
        }
        while(list1){
            ans->next = list1;
            list1=list1->next;
            ans=ans->next;
        }
        while(list2){
            ans->next = list2;
            list2=list2->next;
            ans=ans->next;
        }
        return dummy->next;
    }
};
// @lc code=end

