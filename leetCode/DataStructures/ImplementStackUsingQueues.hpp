// https://leetcode.com/problems/implement-stack-using-queues
class MyStack {
private:
    queue<int> one, two;
    bool topValid = false;
    int topV;
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        topValid = false;
        if (two.empty()) {
            one.push(x);
        } else if (one.empty()) {
            two.push(x);
        } else {
            puts("Error push");
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int resp;
        if (two.empty()) {
            while (one.size() > 1) {
                topV = one.front();
                two.push(topV);
                one.pop();
            }
            resp = one.front();
            one.pop();
            return resp;
        } else if (one.empty()) {
            while (two.size() > 1) {
                topV = two.front();
                one.push(topV);
                two.pop();
            }
            resp = two.front();
            two.pop();
        } else {
            puts("Error pop");
        }
        topValid = true;
        return resp;
    }
    
    /** Get the top element. */
    int top() {
        if (topValid) {
            return topV;
        }
        if (two.empty()) {
            while (!one.empty()) {
                topV = one.front();
                two.push(topV);
                one.pop();
            }
        } else if (one.empty()) {
            while (!two.empty()) {
                topV = two.front();
                one.push(topV);
                two.pop();
            }
        } else {
            puts("Error top");
        }
        topValid = true;
        return topV;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return one.empty() && two.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
 
