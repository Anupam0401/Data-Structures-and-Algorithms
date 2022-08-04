/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
private:
    stack<int> stk;
    int minVal;
public:
    MinStack() {
        minVal = INT_MAX;
    }
    
    void push(int val) {
        if(val<=minVal){
            stk.push(minVal);
            minVal = val;
        }
        stk.push(val);
    }
    
    void pop() {
        if(stk.top()==minVal){
            stk.pop();
            minVal = stk.top();
            stk.pop();
        }
        else    stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

// Approach Overview:
// Used one global stack and one global variable for storing the
// minimum value and then each time performed the following for respective operation:
// - push(): every time while pushing we check if the element is the minimum till then,
//           push the old minimum value first and then the updated new value which then becomes the minimum value for the current state.

// - pop(): if we are going to pop out the minimum element itself, we pop it out and
//          replace the minimum with the next value in the top