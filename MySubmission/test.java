// Given a stack of integers A, sort it using another stack.

// Return the array of integers after sorting the stack using another stack.

public class Solution {

    public Stack<Integer> merge(Stack<Integer> stack){
        if(stack.size() == 1){
            return stack;
        }
        int mid = stack.size()/2;
        Stack<Integer> firstHalf = new Stack<Integer>();
        Stack<Integer> secondHalf = new Stack<Integer>();
        for(int i = 0; i < mid; i++){
            firstHalf.push(stack.pop());
        }
        while(!stack.isEmpty()){
            secondHalf.push(stack.pop());
        }
        firstHalf = merge(firstHalf);
        secondHalf = merge(secondHalf);
        while(!firstHalf.isEmpty() && !secondHalf.isEmpty()){
            if(firstHalf.peek() < secondHalf.peek()){
                stack.push(firstHalf.pop());
            }
            else{
                stack.push(secondHalf.pop());
            }
        }
        while(!firstHalf.isEmpty()){
            stack.push(firstHalf.pop());
        }
        while(!secondHalf.isEmpty()){
            stack.push(secondHalf.pop());
        }
        return stack;
    }
    public ArrayList<Integer> solve(ArrayList<Integer> A) {
        Stack<Integer> stack = new Stack<Integer>();
        for(int i = 0; i < A.size(); i++){
            stack.push(A.get(i));
        }
        stack = merge(stack);
        ArrayList<Integer> ans = new ArrayList<Integer>();
        while(!stack.isEmpty()){
            ans.add(stack.pop());
        }
        return ans;
    }
}