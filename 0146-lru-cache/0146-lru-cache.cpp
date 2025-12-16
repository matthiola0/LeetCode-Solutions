class LRUCache {
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    void addToHead(Node *node) {
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
    }
    void remove(Node *node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    Node *head, *tail;
    int capacity, cur_capacity;
    unordered_map<int, Node*> dict;
public:
    LRUCache(int capacity): capacity(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        cur_capacity = 0;
    }
    
    int get(int key) {
        if (!dict.count(key)) return -1;
        Node *node = dict[key];
        remove(node);
        addToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (!dict.count(key)) {
            Node *node = new Node(key, value);
            dict[key] = node;
            if (cur_capacity == capacity) {
                Node *old = tail->prev;
                remove(old);
                dict.erase(old->key);
                delete old;
            } else {
                cur_capacity++;
            }
            addToHead(node);
        } else {
            Node *node = dict[key];
            node->val = value;
            remove(node);
            addToHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */