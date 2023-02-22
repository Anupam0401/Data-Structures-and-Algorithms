// Given an integer array A containing N distinct integers, you have to find all the leaders in array A. An element is a leader if it is strictly greater than all the elements to its right side.

// NOTE: The rightmost element is always a leader.

public class Solution {
    public int[] solve(int[] A) {
        int n=A.length;
        int maxRight = A[n-1]; //last element is always leader
        int count=1;
        for(int i=n-2;i>=0;i--){
            if(A[i]>maxRight){
                count++;
                maxRight=A[i];
            }
        }
        int[] ans = new int[count];
        ans[count-1]=A[n-1];
        int j=count-2;
        maxRight=A[n-1];
        for(int i=n-2;i>=0;i--){
            if(A[i]>maxRight){
                ans[j]=A[i];
                maxRight=A[i];
                j--;
            }
        }
        return ans;
    }
}