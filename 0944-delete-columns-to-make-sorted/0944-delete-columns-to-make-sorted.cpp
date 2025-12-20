class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        for (int i = 0; i < strs[0].size(); i++) {
            bool unsorted = false;
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] < strs[j-1][i]) {
                    unsorted = true;
                    break;
                }
            }
            if (unsorted) res++;
        }
        return res;
    }
};