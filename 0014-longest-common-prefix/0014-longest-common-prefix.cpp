class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        
        int len = INT_MAX;
        for (int i = 0; i < strs.size(); i++) {
            len = min(len, (int)strs[i].size());
        }

        string res = "";
        for (int i = 0; i < len; i++) {
            bool flag = true;
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != strs[j-1][i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) res += strs[0][i];
            else break;
        }

        return res;
    }
};