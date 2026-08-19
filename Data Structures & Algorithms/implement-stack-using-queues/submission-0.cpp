class MyStack {
private:
    std::queue<int> q;
    int size;
    int newest;
    
    // Cycle the queue to make the newest element the oldest
    void cycle() {
        for (int i = 0; i < size - 1; ++i) {
            int front = q.front();
            newest = front;

            q.pop();
            q.push(front);
        }
    }

public:
    MyStack() : size(0), newest(0) {}
    
    void push(int x) {
        this->newest = x;
        ++size;

        q.push(x);
    }
    
    int pop() {
        cycle();
        int front = q.front();
        q.pop();
        --size;

        return front;
    }
    
    int top() {
        return this->newest;
    }
    
    bool empty() {
        return size == 0;
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