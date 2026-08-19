class MinStack {
private:
    std::vector<int> stack;
    std::unordered_map<int, int> minMap;

    int index;

public:
    MinStack() : index(0) {}
    
    void push(int val) {
        if (!minMap.empty()) {
            if (minMap[index] > val) {
                minMap[index + 1] = val;
            }
            else {
                minMap[index + 1] = minMap[index];
            }

            ++index;
        }
        else {
            minMap[index] = val;
        }

        stack.push_back(val);
    }
    
    void pop() {
        stack.pop_back();
        minMap.erase(index--);
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() { 
        return minMap[index];
    }
};
