**Approach overview :**

We use **stack** data structure for keeping track of the brackets that come along as we traverse the input string.
We push the character to the stack if we encounter an opening bracket i.e., '(' , '[' , or '{' and pop out the top element from the stack if we encounter the closing bracket of the same type that is on the top of the stack.
I hope the basic idea is clear. Let's code it out!

---
**SOLUTION:**
`C++:`

```c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            // push to the stack in case of opening braces of any type
            if(s[i]=='('||s[i]=='['||s[i]=='{')   st.push(s[i]);

            // check for the top element in each case and pop if found its pair
            else if(s[i]==')' && !st.empty() && st.top()=='(')  st.pop();
            else if(s[i]==']' && !st.empty() && st.top()=='[')  st.pop();
            else if(s[i]=='}' && !st.empty() && st.top()=='{')  st.pop();

            //otherwise
            else return false;
        }
        return st.empty(); // if stack is not empty, that implies that some bracket was left unpaired
    }
};
```

`Java:`
```java

class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<Character>();
        for (char c : s.toCharArray()) {
            // push to the stack in case of opening braces of any type
            if(c=='('||c=='['||c=='{')   st.push(c); 
            
            // check for the top element in each case and pop if found its pair
            else if(c==')' && !st.empty() && st.peek()=='(')  st.pop();
            else if(c==']' && !st.empty() && st.peek()=='[')  st.pop();
            else if(c=='}' && !st.empty() && st.peek()=='{')  st.pop();
            
            //otherwise
            else return false;
        }
        return st.isEmpty(); // if stack is not empty, that implies that some bracket was left unpaired
    }
}
```
---
**Analysis:**
Time Complexity: O(n) (we traverse the whole string once in worst case)
Space Complexity: O(n) (taken up by the stack)

Please upvoke if you understood the solution, any doubts are welcomed.


