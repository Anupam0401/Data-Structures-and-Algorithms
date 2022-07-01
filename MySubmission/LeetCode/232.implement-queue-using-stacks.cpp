/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
private:
    stack<int> mem;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int> temp;
        while(!mem.empty())
        {
            temp.push(mem.top());
            mem.pop();
        }
        
        mem.push(x);
        while(!temp.empty())
        {
            mem.push(temp.top());
            temp.pop();
        }
    }
    
    int pop() {
        int p = mem.top();
        mem.pop();
        return p;
    }
    
    int peek() {
        return mem.top();
    }
    
    bool empty() {
        return mem.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
