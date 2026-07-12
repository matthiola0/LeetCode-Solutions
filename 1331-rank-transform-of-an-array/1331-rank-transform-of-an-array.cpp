class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        int rank = 1;
        unordered_map<int, int> ranks;
        for (int num : sortedArr) {
            if (ranks.find(num) == ranks.end()) {
                ranks[num] = rank++;
            }
        }
        
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = ranks[arr[i]];
        }
        
        return arr;
    }
};