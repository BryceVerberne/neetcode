class MedianFinder {
private:
    priority_queue<int> m_small;              // MaxHeap
    priority_queue<int,std::vector<int>,std::greater<int>> m_large; // MinHeap

public:
    MedianFinder() {}
    
    void addNum(int num) {
        // Empty case
        if (m_small.empty()) {
            m_small.push(num);
            return;
        }

        // Ensure balance values
        if (num <= m_small.top()) {
            m_small.push(num);
        }
        else {
            m_large.push(num);
        }

        // Rebalance O(log(n))
        if (m_small.size() > m_large.size() + 1) {
            m_large.push(m_small.top());
            m_small.pop();
        }
        else if (m_large.size() > m_small.size()) {
            m_small.push(m_large.top());
            m_large.pop();
        }
    }
    
    double findMedian() {
        int smallSize = static_cast<int>(m_small.size());
        int largeSize = static_cast<int>(m_large.size());

        double res;

        // Find median O(1)
        if (smallSize == largeSize) {
            if (m_small.empty()) {
                return 0.0;
            }

            res = (m_large.top() + m_small.top()) / 2.0;
        }
        else if (smallSize > largeSize) {
            res = static_cast<double>(m_small.top());
        }
        else {
            res = static_cast<double>(m_large.top());
        }

        return res;
    }
};
