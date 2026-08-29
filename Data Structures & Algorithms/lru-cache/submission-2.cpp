class LRUCache {
private:
    struct ListNode {
        int key;
        int val;

        ListNode* prev;
        ListNode* next;

        ListNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
        ListNode(int key, int num) : key(key), val(num), prev(nullptr), next(nullptr) {}
    };

    unordered_map<int, ListNode*> cacheMap;
    ListNode* dummyHead;
    ListNode* tail;
    int capacity;
    int size;

    void hit(ListNode* node) {
        if (!node->next) { // Already in order
            return;
        }

        // Reorder the list
        node->prev->next = node->next;
        node->next->prev = node->prev;

        // Move node to tail
        tail->next = node;
        node->prev = tail;
        node->next = nullptr;
        tail = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        dummyHead = new ListNode();
        tail = dummyHead;
    }
    
    int get(int key) {
        if (!cacheMap.contains(key)) {
            return -1;
        }

        ListNode* node = cacheMap[key];
        hit(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if (!cacheMap.contains(key)) {
            ListNode* node = new ListNode(key, value);
            cacheMap[key] = node;
        
            tail->next = node;
            node->prev = tail;
            tail = node;

            ++size;
        }
        else {
            ListNode* node = cacheMap[key];
            node->val = value;
            hit(node);
            return;
        }
        
        if (size > capacity) {
            ListNode* target = dummyHead->next;
            dummyHead->next = target->next;
            target->next->prev = dummyHead;

            cacheMap.erase(target->key);
            delete target;
            --size;
        }
    }
};
