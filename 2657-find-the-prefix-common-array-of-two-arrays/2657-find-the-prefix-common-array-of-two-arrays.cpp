class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> C;
        unordered_set<int> s;
        int cnt = 0;
        for (int i = 0; i < A.size(); i++) {
            if (!s.count(A[i])) {
                s.insert(A[i]);
            } else {
                cnt++;
            }

            if (!s.count(B[i])) {
                s.insert(B[i]);
            } else {
                cnt++;
            }

            C.push_back(cnt);
        }
        return C;
    }
};