class LRUCache {
private:
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    void addToHead(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
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
            Node* node = dict[key];
            removeNode(node);
            addToHead(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (dict.count(key)) {
            Node* node = dict[key];
            removeNode(node);
            addToHead(node);
            node->val = value;
        } else {
            Node* node = new Node(key, value);
            dict[key] = node;
            if (capacity == cur_capacity) {
                Node* old = tail->prev;
                removeNode(old);
                dict.erase(old->key);
                delete old;
                addToHead(node);
            } else {
                addToHead(node);
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