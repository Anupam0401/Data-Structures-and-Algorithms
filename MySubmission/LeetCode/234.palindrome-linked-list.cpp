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
    // bool isPalindrome(ListNode* head) {
    //     // brute force, highly uneconomical approach
    //     vector<int> nums;
    //     ListNode* temp = head;
    //     while (temp!=NULL)
    //     {   
    //         nums.push_back(temp->val);
    //         temp = temp->next;
    //     }
    //     int n = nums.size();
    //     for(int i=0;i<=(n-1)/2;i++){
    //         if(nums[i]!=nums[n-1-i])    return false;
    //     }
    //     return true;
    // }
    ListNode* reverse(ListNode* head){
        ListNode *prev = NULL, *curr =  head;
        while(curr!=NULL){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)  return true;
        // finding the middle of the linked list
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;
        
        while(slow!=NULL){
            cout<<slow->val<<" "<<head->val;
            if(slow->val!=head->val){
                return false;
            }
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};
// @lc code=end

