class Solution {
public:
    string simplifyPath(string path) {
        vector<string> components;
        stringstream ss(path);
        string cur;
        while (getline(ss, cur, '/')) {
            if (cur == "" || cur == ".") continue;
            if (cur == "..") {
                if (!components.empty()) components.pop_back();
            } else {
                components.push_back(cur);
            }
        }
        string res = "";
        for (int i = 0; i < components.size(); i++) {
            res += "/" + components[i];
        }
        return res.size() == 0 ? "/" : res;
    }
};