class RandomizedSet {
private:
    unordered_map<int, int> dict;   // val, idx
    vector<int> v;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (dict.count(val)) {
            return false;
        }
        dict[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!dict.count(val)) {
            return false;
        }
        int i = dict[val];
        dict.erase(val);
        v[i] = v.back();
        dict[v[i]] = i;
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */