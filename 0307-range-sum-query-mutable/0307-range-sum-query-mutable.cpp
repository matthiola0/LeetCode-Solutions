class NumArray {
private:
    vector<int> bit, nums;

    int lowbit(int i) { return i & (-i); }
    int query(int idx) {
        int res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= lowbit(idx);
        }
        return res;
    }

public:
    NumArray(vector<int>& nums) {
        this->nums.assign(nums.size(), 0);
        bit.assign(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            update(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;

        int idx = index + 1;
        while (idx <= nums.size()) {
            bit[idx] += diff;
            idx += lowbit(idx);
        }
    }
    
    int sumRange(int left, int right) {
        return query(right + 1) - query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */