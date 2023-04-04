// You are given a linked list that contains a loop.
// You need to find the node, which creates a loop and break it by making the node point to NULL.

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     public int val;
 *     public ListNode next;
 *     ListNode(int x) { val = x; next = null; }
 * }
 */
public class Solution {
    public ListNode solve(ListNode A) {

        if(A == null) return A;

        ListNode fast = A;
        ListNode slow = A;
        int flag = 0;

        while(fast != null && fast.next != null){
			fast = fast.next.next;
			slow = slow.next;
			if(fast == slow){
				flag = 1;
				break;
			}
		}

		if(flag == 1){
			slow = A;
			while(slow.next != fast.next){
				slow = slow.next;
				fast = fast.next;
			}
			fast.next = null;
		}

		return A;
    }
}
