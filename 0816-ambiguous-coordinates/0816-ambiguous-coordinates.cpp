class Solution {
    vector<string> getValidNumbers(string num) {
        int len = num.size();
        vector<string> valids;
        
        if (len == 1 || num[0] != '0') {
            valids.push_back(num);
        }

        for (int j = 1; j < len; ++j) {
            string integerPart = num.substr(0, j);
            string fractionalPart = num.substr(j);

            if (integerPart.size() > 1 && integerPart[0] == '0') continue;
            if (fractionalPart.back() == '0') continue;

            valids.push_back(integerPart + "." + fractionalPart);
        }
        return valids;
    }

public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> res;
        string content = s.substr(1, s.size() - 2);
        int n = content.size();

        for (int i = 1; i < n; ++i) {
            string leftStr = content.substr(0, i);
            string rightStr = content.substr(i);

            vector<string> leftCandidates = getValidNumbers(leftStr);
            vector<string> rightCandidates = getValidNumbers(rightStr);

            for (const string& l : leftCandidates) {
                for (const string& r : rightCandidates) {
                    res.push_back("(" + l + ", " + r + ")");
                }
            }
        }
        return res;
    }    
};