class BIT {
private:
    vector<int> tree;
    int size;
public:
    BIT(int n) {
        size = n + 1;
        tree.resize(size, 0);
    }
    void update(int index, int delta) {
        while (index < size) {
            tree[index] += delta;
            index += index & (-index);
        }
    }
    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & (-index);
        }
        return sum;
    }
};
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> P(n + 1, 0);
        int score = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                score++;
            } else {
                score--;
            }
            P[i + 1] = score;
        }

        int bit_size = 2 * n + 2;
        BIT bit(bit_size);

        long long total_count = 0;
        for (int k = 0; k <= n; k++) {
            int cur = P[k];
            int map_val = cur + n + 1;

            int count_smaller = bit.query(map_val - 1);
            total_count += count_smaller;
            bit.update(map_val, 1);
        }
        return total_count;
    }
};