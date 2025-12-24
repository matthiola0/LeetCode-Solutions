class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());
        int cnt = 1;
        for (int c : capacity) {
            sum -= c;
            if (sum <= 0) return cnt;
            cnt++;
        }
        return -1;
    }
};