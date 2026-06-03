class LRUCache {
    class DLLNode {
    public:
        int key, val;
        DLLNode *prev, *next;
        DLLNode(int key, int val) {
            this->key = key, this->val = val;
        } 
    };

    DLLNode *head, *tail;
    int size, capacity;
    unordered_map<int, DLLNode*> mp;
public:
    LRUCache(int capacity) {
        size = 0, this->capacity = capacity;
        head = tail = nullptr;
    }

    void insertAtHead(DLLNode* node) {
        if(!head) {
            node->next = node->prev = nullptr;
            head = tail = node;
            return;
        }
        node->next = head; node->prev = nullptr;
        head->prev = node;
        head = node;
    }

    void deleteFromList(DLLNode* node) {
        DLLNode *prv = node->prev, *nxt = node->next;
        if(prv) prv->next = nxt;
        if(nxt) nxt->prev = prv;
        if(head == tail) {
            head = tail = nullptr; 
            return;
        }
        if(tail == node) tail = prv;
        if(head == node) head = nxt;
    }
    
    void deleteTail() {
        tail->prev->next = nullptr;
        DLLNode* node = tail;
        tail = tail->prev;
        mp.erase(node->key);
        delete node;
    }

    int get(int key) {
        if(!mp.count(key)) return -1;
        DLLNode* node = mp[key];
        deleteFromList(node);
        insertAtHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            DLLNode* node = mp[key];
            deleteFromList(node);
            node->val = value;
            insertAtHead(node);
        } else {
            DLLNode* node = new DLLNode(key, value);
            insertAtHead(node);
            mp[key] = node;
            ++size;
            if(size == capacity+1) {
                --size;
                deleteTail();
            }
        }
    }
};
