class Node {
public:
    int val;
    Node* next;
    Node(int val): val(val), next(nullptr) {}
};
class MyLinkedList {
private:
    Node* head;
    int size;
public:
    MyLinkedList() {
        head = new Node(0);
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        
        Node* cur = head->next;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return; 

        Node* newNode = new Node(val);
        Node* cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        Node* cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        Node* temp = cur->next;
        cur->next = temp->next;
        delete temp;
        size--;
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