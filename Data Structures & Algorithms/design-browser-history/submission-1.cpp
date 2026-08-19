class BrowserHistory {
private: 
    struct WebList {
        std::string url;

        WebList* prev;
        WebList* next;

        WebList() : prev(nullptr), next(nullptr) {}
        WebList(std::string url) : url(url), prev(nullptr), next(nullptr) {}
    };

    WebList* dummyHead;
    WebList* dummyTail;

    WebList* page;
    int position;
    int size;

    void clearForward() {
        WebList* marked = page->next;
        WebList* cur = marked->next;
        page->next = dummyTail;

        int index = position + 1;

        // Clear allocated memory
        while (index <= size) {
            delete marked;
            marked = nullptr;

            marked = cur;
            cur = marked->next;

            ++index;
            --size;
        }
    }

public:
    BrowserHistory(string homepage) : size(1), position(1) {
        dummyHead = new WebList();
        dummyTail = new WebList();
        WebList* node = new WebList(homepage);

        // Wire it up
        dummyHead->next = node;
        node->prev = dummyHead;
        node->next = dummyTail;
        dummyTail->prev = node;

        // Set the current page
        page = node;
    }
    
    void visit(string url) {
        clearForward();

        WebList* node = new WebList(url);
        page->next = node;
        node->prev = page;
        node->next = dummyTail;
        dummyTail->prev = node;

        page = node;
        ++size;
        ++position;
    }
    
    string back(int steps) {
        for (int i = 0; i < steps && position > 1; ++i) {
            page = page->prev;
            --position;
        }

        return page->url;
    }
    
    string forward(int steps) {
        for (int i = 0; i < steps && size > position; ++i) {
            page = page->next;
            ++position;
        }

        return page->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */