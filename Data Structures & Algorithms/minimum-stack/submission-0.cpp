class MinStack {
private:
    std::vector<int> stack;

public:
    MinStack() {}
    
    void push(int val) { // O(1)
        stack.push_back(val);
    }
    
    void pop() { // O(1)
        stack.pop_back();
    }
    
    int top() { // O(1)
        return stack.back();
    }
    
    int getMin() { // O(n)
        int min = stack.back();
        for (const int& val : stack) {
            if (val < min) min = val;
        }
        return min;
    }
};
