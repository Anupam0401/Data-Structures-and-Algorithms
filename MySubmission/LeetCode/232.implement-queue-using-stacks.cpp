/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
private:
    queue<int> q;
public:
    MyQueue() {
        // q.clear();
    }
    
    void push(int x) {
        q.push(x);
        return;
    }
    
    int pop() {
        int x = q.front();
        q.pop();
    }
    
    int peek() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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

