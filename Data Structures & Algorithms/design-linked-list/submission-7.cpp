class MyLinkedList {
private:
    struct ListNode {
        int val;
        ListNode* prev;
        ListNode* next;

        ListNode() : val(0), prev(nullptr), next(nullptr) {}
        ListNode(int val) : val(val), prev(nullptr), next(nullptr) {}
    };

    ListNode* dummyHead;
    ListNode* dummyTail;

    int size;

    ListNode* getNode(int index) {
        ListNode* cur = dummyHead->next;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }

        return cur;
    }

public:
    MyLinkedList() : size(0) {
        dummyHead = new ListNode();
        dummyTail = new ListNode();

        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;

        return getNode(index)->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* curHead = dummyHead->next;
        
        // Rewire
        dummyHead->next = newNode;
        curHead->prev = newNode;
        newNode->prev = dummyHead;
        newNode->next = curHead;

        ++size;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* curTail = dummyTail->prev;

        // Rewire
        dummyTail->prev = newNode;
        curTail->next = newNode;
        newNode->next = dummyTail;
        newNode->prev = curTail;

        ++size;
    }
    
    void addAtIndex(int index, int val) {
        if ((size < index) || (index < 0)) return;

        ListNode* cur = getNode(index);
        ListNode* prev = cur->prev;
        ListNode* node = new ListNode(val);

        node->prev = prev;
        node->next = cur;
        cur->prev = node;
        prev->next = node;

        ++size;
    }
    
    void deleteAtIndex(int index) {
        if ((index >= size) || (index < 0)) return;

        ListNode* node = getNode(index);
        ListNode* prev = node->prev;
        ListNode* cur = node->next;

        prev->next = cur;
        cur->prev = prev;

        delete node;
        node = nullptr;

        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */