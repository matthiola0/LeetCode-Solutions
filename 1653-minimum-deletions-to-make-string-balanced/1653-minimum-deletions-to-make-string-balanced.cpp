class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int delB = 0, delA = 0;

        int ans = n;

        for (char& c: s) {
            if (c == 'a') {
                delA++;
            }
        }
        ans = min(ans, delA);

        for (char& c: s) {
            if (c == 'a') {
                delA--;
            } else if (c == 'b') {
                delB++;
            }
            ans = min(ans, delA + delB);
        }

        return ans;
    }
};