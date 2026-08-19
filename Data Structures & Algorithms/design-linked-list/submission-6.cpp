class MyLinkedList {
private:
    struct ListNode {
        int val;
        ListNode* prev;
        ListNode* next;

        ListNode() : val(0), prev(nullptr), next(nullptr) {}
        ListNode(int val) : val(val), prev(nullptr), next(nullptr) {}
    };

    ListNode* head;
    ListNode* tail;

    int size;

    // Helper function that gets the node at a given index
    ListNode* getNode(int index) {
        if (index < 0 || index >= size) return nullptr;
        ListNode* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        return current;
    }

public:
    MyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    int get(int index) {
        // Check index validity
        if (index < 0 || index >= size) {
            return -1;
        }
        return getNode(index)->val;
    }
    
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);

        if (!head) {
            head = node;
            tail = head;
        }
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }

        ++size;
    }
    
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);

        if (!head) {
            head = node;
            tail = head;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

        ++size;
    }
    
    void addAtIndex(int index, int val) {
        if (index <= 0) { // Insert at head
            addAtHead(val);
        }
        else if (index == size) { // Insert at tail
            addAtTail(val);
        }
        else if (index < size) { // Traverse LL to insert new element
            ListNode* current = getNode(index);
            ListNode* prev = current->prev;

            ListNode* newNode = new ListNode(val);

            // Restructure node communication
            prev->next = newNode;
            current->prev = newNode;
            newNode->next = current;
            newNode->prev = prev;

            ++size;
        }
    }
    
    void deleteAtIndex(int index) {
        if (head && index >= 0 && index < size) {
            if (index == 0) { // Handle head cases
                // Check for cases where the list is a size of 1
                if (size == 1) {
                    delete head;
                    head = nullptr;
                    tail = nullptr;
                }
                else {
                    ListNode* victim = head;
                    head = head->next;
                    head->prev = nullptr;
                    delete victim;
                }

                --size;
            }
            else if (index == (size - 1)) { // Handle tail cases
                // Check for cases where the list is a sizes of 1
                if (size == 1) {
                    delete head;
                    head = nullptr;
                    tail = nullptr;
                }
                else {
                    ListNode* victim = tail;
                    tail = tail->prev;
                    tail->next = nullptr;
                    delete victim;
                }

                --size;
            }
            else if ((index < (size - 1)) && (index > 0)) { // Handle standard case
                ListNode* victim = getNode(index);
                ListNode* prev = victim->prev;
                ListNode* next = victim->next;

                prev->next = next;
                next->prev = prev;

                delete victim;
                victim = nullptr;

                --size;
            }
        }
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