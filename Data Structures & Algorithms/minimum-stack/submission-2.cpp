class MinStack {
private:
    std::stack<int> numStack;
    std::stack<int> minStack;

public:
    MinStack() {}
    
    void push(int val) {
        numStack.push(val);

        // Track the min
        if (!minStack.empty()) {
            if (minStack.top() > val) {
                minStack.push(val);
            }
            else {
                minStack.push(minStack.top());
            }
        }
        else {
            minStack.push(val);
        }
    }
    
    void pop() {
        numStack.pop();
        minStack.pop();
    }
    
    int top() {
        return numStack.top();
    }
    
    int getMin() { 
        return minStack.top();
    }
};
