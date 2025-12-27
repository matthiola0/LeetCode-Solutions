class WordDictionary {
private:
    struct Node {
        vector<Node*> children;
        bool isEnd;
        
        Node() : isEnd(false) {
            children = vector<Node*>(26, nullptr);
        }
    };

    Node* root;

    bool searchHelper(string& word, int idx, Node* node) {
        Node* cur = node;
        if (idx == word.size()) {
            return node->isEnd;
        }

        char c = word[idx];
        if (c == '.') {
            for (auto ch : cur->children) {
                if (ch && searchHelper(word, idx + 1, ch)) return true;
            }
            return false;
        } else {
            if (!cur->children[c-'a']) return false;
            return searchHelper(word, idx + 1, node->children[c-'a']);
        }
    }
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = root;
        for (char c: word) {
            if (!cur->children[c-'a']) {
                cur->children[c-'a'] = new Node();
            }
            cur = cur->children[c-'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */