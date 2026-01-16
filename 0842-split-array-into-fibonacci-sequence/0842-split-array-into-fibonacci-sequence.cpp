class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        // if (num[0] == '0') return {};

        vector<int> res;
        if (backtrack(num, 0, res)) return res;
        return {};
    }

    bool backtrack(string& num, int index, vector<int>& res) {
        if (index == num.length()) {
            return res.size() >= 3;
        }

        long long cur = 0;
        
        for (int i = index; i < num.length(); i++) {
            if (i - index >= 1 && num[index] == '0') break;

            cur = cur * 10 + (num[i] - '0');
            if (cur > INT_MAX) break;

            if (res.size() >= 2) {
                long long sum = (long long)res.rbegin()[0] + res.rbegin()[1];
                if (cur > sum) break;
                if (cur < sum) continue;
            }

            res.push_back(cur);
            if (backtrack(num, i + 1, res)) return true;
            
            res.pop_back();
        }
        
        return false;
    }
};