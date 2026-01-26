class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int minDiff = INT_MAX;

        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 1; i++) {
            int diff = arr[i+1] - arr[i];
            if (diff < minDiff) {
                res.clear();
                res.push_back({arr[i], arr[i+1]});
                minDiff = diff;
            } else if (diff == minDiff) {
                res.push_back({arr[i], arr[i+1]});
            }
        }
        return res;
    }
};