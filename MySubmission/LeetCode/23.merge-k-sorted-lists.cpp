/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeTwoLists(ListNode *left, ListNode *right){
        if(left == NULL) return right;
        if(right == NULL) return left;
        ListNode *head = NULL;
        if(left->val < right->val){
            head = left;
            left = left->next;
        }
        else{
            head = right;
            right = right->next;
        }
        ListNode *cur = head;
        while(left != NULL && right != NULL){
            if(left->val < right->val){
                cur->next = left;
                left = left->next;
            }
            else{
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        if(left != NULL) cur->next = left;
        if(right != NULL) cur->next = right;
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        ListNode* head = lists[0];
        for(int i = 1; i < lists.size(); i++)
            head = mergeTwoLists(head, lists[i]);
        return head;
    }
};

// @lc code=end

