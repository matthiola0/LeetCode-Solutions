class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int i = 0;
        for (; i < citations.size(); i++) {
            if (i + 1 > citations[i]) break;
        }
        return i;
    }
};