class Solution {
public:
    string removeStars(string s) {
        string res;
        for (char c : s) {
            if (c != '*') {
                res.push_back(c);
            } else if (!res.empty()) {
                res.pop_back();
            }
        }
        return res;
    }
};

