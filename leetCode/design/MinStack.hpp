//https://leetcode.com/problems/min-stack/
class MinStack {
private:
    stack<int> data;
    stack<int> min;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        data.push(x);
        if (min.size() == 0) {
            min.push(x);
        } else {
            int v = min.top();
            min.push(v < x ? v : x);
        }
    }
    
    void pop() {
        data.pop();
        min.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
