class LRUCache {
private:
    struct Node {
        Node *next, *prev;
        int key, val;
        Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
    };

    void removeNode(Node *node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    void addToHead(Node *node) {
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
    }

    unordered_map<int, Node*> dict;
    Node *head, *tail;
    int capacity, cur_capacity;

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        cur_capacity = 0;
    }
    
    int get(int key) {
        if (dict.count(key)) {
            removeNode(dict[key]);
            addToHead(dict[key]);
            return dict[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (dict.count(key)) {
            dict[key]->val = value;
            removeNode(dict[key]);
            addToHead(dict[key]);
        } else {
            dict[key] = new Node(key, value);
            if (cur_capacity == capacity) {
                Node *old = tail->prev;
                removeNode(old);
                dict.erase(old->key);
                delete old;
                addToHead(dict[key]);
            } else {
                addToHead(dict[key]);
                cur_capacity++;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */