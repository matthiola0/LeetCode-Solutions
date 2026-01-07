class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        for (int num: arr) {
            if (stk.empty() || num >= stk.top()) {
                stk.push(num);
            } else {
                int curMax = stk.top();
                while (!stk.empty() && num < stk.top()) {
                    stk.pop();
                }
                stk.push(curMax);
            }
        }
        return stk.size();
    }
};