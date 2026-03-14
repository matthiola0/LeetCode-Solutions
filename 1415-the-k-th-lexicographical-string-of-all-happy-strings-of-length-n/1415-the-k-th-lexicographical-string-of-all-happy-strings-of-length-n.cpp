class Solution {
public:
    string getHappyString(int n, int k) {
        int cur = 0;
        string s = "";
        s.resize(n);
        string ans = "";

        auto backtrack = [&](auto& self, int i) -> void {
            if (!ans.empty()) return;

            if (i == n) {
                if (++cur == k) ans = s;
                return;
            }

            for (char c = 'a'; c <= 'c'; c++) {
                if (i > 0 && c == s[i - 1]) continue;
                
                s[i] = c;
                self(self, i + 1);
            }
        };

        backtrack(backtrack, 0);
        return ans;
    }
};