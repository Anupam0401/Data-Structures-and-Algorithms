/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        // if(head==NULL)  return head;
        // if(head->next==NULL && head->val == val) return NULL;
        // // while (head->val == val)
        // // {
        // //     if(head==NULL)  return NULL;
        // //     head = head->next;
        // //     // if(head->next->val == val)  return NULL;
        // // }
        // ListNode *newNode = new ListNode();
        // newNode->next = head;
        // ListNode *temp = newNode;
        // while(temp->next!=NULL){
        //     if(temp->next->val == val){
        //         if(temp->next->next!=NULL)  temp->next=temp->next->next;
        //         else{
        //             temp->next=NULL;
        //             break;
        //         }
        //     }
        //     // if(temp->next->next == NULL && temp->next->val == val)    temp->next=temp->next->next;
        //     temp=temp->next;
        // }
        // return newNode->next;
        if(head==NULL) return NULL;
        head->next = removeElements(head->next,val);
        return head->val==val?head->next:head;
    }
};
// @lc code=end

