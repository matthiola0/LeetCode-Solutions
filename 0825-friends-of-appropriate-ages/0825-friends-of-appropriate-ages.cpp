class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> num(121), pre(121);
        for (int i = 0; i < ages.size(); i++) {
            num[ages[i]]++;
        }

        for (int i = 1; i <= 120; i++) {
            pre[i] = pre[i-1] + num[i];
        }

        int res = 0;
        for (int i = 1; i <= 120; i++) {
            if (num[i] == 0) continue;

            int tar = i / 2 + 7;
            if (tar < i) {
                res += (pre[i-1] - pre[tar]) * num[i];
                res += num[i] * (num[i] - 1);
            }
        }

        return res;


    }
};