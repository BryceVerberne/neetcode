class MedianFinder {
private:
    priority_queue<int> m_small;              // MaxHeap
    priority_queue<int,std::vector<int>,std::greater<int>> m_large; // MinHeap

public:
    MedianFinder() {}
    
    void addNum(int num) {
        m_small.push(num);

        // Ensure balance values
        if (!m_large.empty()) {
            if (m_small.top() > m_large.top()) {
                m_large.push(m_small.top());
                m_small.pop();
            }
        }

        // Rebalance O(log(n))
        int smallSize = static_cast<int>(m_small.size());
        int largeSize = static_cast<int>(m_large.size());
        if (abs(smallSize - largeSize) >= 2) {
            if (smallSize > largeSize) {
                m_large.push(m_small.top());
                m_small.pop();
            }
            else {
                m_small.push(m_large.top());
                m_large.pop();
            }
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

            res = (static_cast<double>(m_large.top()) + static_cast<double>(m_small.top())) / 2.0;
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
