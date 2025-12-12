class RandomizedSet {
private:
	unordered_map<int, int> dict;
	vector<int> v;
public:
    RandomizedSet() {}
   
    bool insert(int val) {
    	if (dict.count(val)) return false;
            v.push_back(val);
            dict[val] = v.size() - 1;
        return true;
    }
   
    bool remove(int val) {
    	if (!dict.count(val)) return false; 
        
        int change_val = v.back();
        v[dict[val]] = change_val; 
        dict[change_val] = dict[val];
        v.pop_back();
        dict.erase(val);
        return true;
    }
   
    int getRandom() {
    	return v[random() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


