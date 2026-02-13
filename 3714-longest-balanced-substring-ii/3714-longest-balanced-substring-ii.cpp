class Solution {
    int one(string& s) {
        int cur = 0;
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && s[i] == s[i-1]) {
                cur++;
            } else {
                cur = 1;
            }
            max_len = max(max_len, cur);
        }
        return max_len;
    }

    int two(string& s) {
        int max_len = 0;

        auto solve = [&](char c1, char c2) {
            int local_max = 0;
            int balance = 0;

            unordered_map<int, int> mp;
            mp[0] = -1;

            for (int i = 0; i < s.size(); i++) {
                if (s[i] != c1 && s[i] != c2) {
                    mp.clear();
                    mp[0] = i;
                    balance = 0;
                } else {
                    if (s[i] == c1) balance++;
                    else if (s[i] == c2) balance--;

                    if (mp.count(balance)) {
                        local_max = max(local_max, i - mp[balance]);
                    } else {
                        mp[balance] = i;
                    }
                }
            }
            return local_max;
        };

        max_len = max(max_len, solve('a', 'b'));
        max_len = max(max_len, solve('b', 'c'));
        max_len = max(max_len, solve('a', 'c'));
        return max_len;
    }

    int three(string& s) {
        int max_len = 0;

        unordered_map<string, int> mp;
        mp["0,0"] = -1;

        int ca = 0, cb = 0, cc = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') ca++;
            else if (s[i] == 'b') cb++;
            else cc++;

            int diff1 = ca - cb;
            int diff2 = cb - cc;

            string key = to_string(diff1) + "," + to_string(diff2);

            if (mp.count(key)) {
                max_len = max(max_len, i - mp[key]);
            } else {
                mp[key] = i;
            }
        }

        return max_len;
    }

public:
    int longestBalanced(string s) {
        int res = 0;
        int len;

        len = one(s);
        res = max(res, len);
        len = two(s);
        res = max(res, len);
        len = three(s);
        res = max(res, len);

        return res;
    }
};