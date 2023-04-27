// You are given an array A of N elements. You have to make all elements unique. To do so, in one step you can increase any number by one.

// Find the minimum number of steps.

public class Solution {
    public int solve(int[] A) {
        Arrays.sort(A);
        int c = 0;
		for(int i = 1; i < A.length; i++){
			if(A[i] <= A[i-1]){
				c += A[i-1] - A[i] + 1;
				A[i] = A[i-1] + 1;
			}
		}
		return c;
	}
}
