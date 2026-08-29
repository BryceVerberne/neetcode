class KthLargest {
private: 
    vector<int> heap;
    int largest;

    void helper(int index) {
        if (heap.size() <= 1) { // heap is empty
            return;
        }

        int target = index;
        int left = target * 2;
        int right = left + 1;
        int size = static_cast<int>(heap.size()) - 1;

        // Propagate root down
        while (left <= size) {
            if ((right <= size) &&
                (heap[left] > heap[right]) &&
                (heap[target] > heap[right])) { // Right-hand
                int tmp = heap[target];
                heap[target] = heap[right];
                heap[right] = tmp;
                target = right;
            }
            else if (heap[target] > heap[left]) { // Left-hand
                int tmp = heap[target];
                heap[target] = heap[left];
                heap[left] = tmp;
                target = left;
            }
            else {
                break;
            }

            left = target * 2;
            right = left + 1;
        }
    }

    void heapify() { // O(n)
        int size = static_cast<int>(heap.size()) - 1;
        if (size <= 1) {
            return;
        }

        int current = size / 2;
        while (current > 0) {
            helper(current);
            --current;
        }
    }

    int pop() { // O(log(n))
        if (heap.size() <= 1) { // heap is empty
            return -1;
        }

        // Get min
        int res = heap[1];

        // Move bottom to top (preserve structure)
        heap[1] = heap.back();
        heap.pop_back();

        // Propagate down from first element of heap
        helper(1);

        // Return min
        return res;
    }

    void push(int val) { // O(log(n))
        heap.push_back(val);
        int target = static_cast<int>(heap.size()) - 1;
        int parent = target / 2;

        while (parent > 0) {
            if (heap[target] < heap[parent]) {
                int tmp = heap[target];
                heap[target] = heap[parent];
                heap[parent] = tmp;
                target = parent;
                parent /= 2;
            }
            else {
                return;
            }
        }
    }

public:
    KthLargest(int k, vector<int>& nums) {
        this->heap = nums;

        // Fill dummy node
        if (heap.empty()) {
            heap.push_back(0);
        }
        else {
            heap.push_back(heap[0]);
        }

        this->largest = k;
        heapify();

        // Limit heap to k-length
        int size = static_cast<int>(heap.size()) - 1;
        while (size > largest) {
            pop();
            --size;
        }
    }
    
    int add(int val) {
        push(val);

        if ((static_cast<int>(heap.size()) - 1) > largest) {
            pop();
        }

        return heap[1];
    }
};
