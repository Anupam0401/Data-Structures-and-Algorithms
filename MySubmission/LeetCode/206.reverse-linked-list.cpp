/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)  return NULL;
        stack<int> st;
        while(head->next!= NULL){
            st.push(head->val);
            head = head->next;
        }
        // ListNode* new_head = new ListNode(st.top());
        // st.pop();
        // ListNode* curr = new_head;
        // while(!st.empty()){
        //     curr->next = new ListNode(st.top());
        //     st.pop();
        //     curr = curr->next;
        // }
        // return new_head;
        ListNode *temp = head;
        while(!st.empty()){
            temp->next = new ListNode(st.top());
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};
// @lc code=end

