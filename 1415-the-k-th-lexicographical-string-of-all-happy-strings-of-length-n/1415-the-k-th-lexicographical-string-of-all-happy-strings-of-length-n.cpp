class Solution {
public:
    string getHappyString(int n, int k) {
        int cur = 0;
        string s = "";
        s.resize(n);
        string ans = ""; // 用來儲存最終答案

        // 使用 [&] 捕獲所有外部變數的參考
        // 傳入 auto& self 是為了解決 Lambda 自己呼叫自己的編譯限制
        auto backtrack = [&](auto& self, int i) -> void {
            // 已經找到答案了，直接提早結束後續無用的遞迴
            if (!ans.empty()) return; 

            // Base case: 字串長度達到 n
            if (i == n) {
                cur++; // 累加找到的合法字串數量
                if (cur == k) {
                    ans = s; // 找到第 k 個，儲存答案
                }
                return;
            }

            // Recursive step: 嘗試填入 a, b, c
            for (char c = 'a'; c <= 'c'; c++) {
                // 如果不是第一個字元，且和前一個字元相同，則跳過
                if (i > 0 && c == s[i - 1]) continue;
                
                s[i] = c;
                self(self, i + 1); // 遞迴呼叫自己
            }
        };

        backtrack(backtrack, 0); // 啟動回溯
        return ans;
    }
};