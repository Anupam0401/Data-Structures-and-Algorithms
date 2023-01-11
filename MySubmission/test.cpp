public class Solution {

    public Stack<Integer> merge(Stack<Integer> stack){
        
        if(stack.size()<=1) 
        {
           // System.out.print(stack.peek()+", ");
            return stack;
        }
        int size=stack.size();

        Stack<Integer> sstack= new Stack<>();
        
        for(int i=1; i<=size/2;i++){
            sstack.push(stack.pop());
        }
n
        Stack<Integer> firstHalf= new Stack<>();
        Stack<Integer> secondHalf= new Stack<>();

        firstHalf=merge(sstack);
        secondHalf=merge(stack);

        Stack<Integer> resultantStack= new Stack<>();

        while(!firstHalf.empty() && !secondHalf.empty()){
            if(firstHalf.peek()<secondHalf.peek()){
                resultantStack.push(firstHalf.pop());
            }
            else{
                 resultantStack.push(secondHalf.pop());
            }
        }

            while(!firstHalf.empty()){
                 resultantStack.push(firstHalf.pop());
            }

            while(!secondHalf.empty()){
                 resultantStack.push(secondHalf.pop());
            }
            return resultantStack;
    }

    public ArrayList<Integer> solve(ArrayList<Integer> A) {
        if(A.size()<=1) return A;
        
        Stack<Integer> stack = new Stack<>();

        for(Integer i: A){
            stack.push(i);
        }

        Stack<Integer> ans= merge(stack);
        ArrayList<Integer> list= new ArrayList<>();
       
        while(!ans.empty()){
            list.add(ans.pop());
        }

        return list;

    }
}