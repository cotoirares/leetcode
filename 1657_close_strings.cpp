class Solution {
public:
    bool closeStrings(string word1, string word2) {
    if (word1.length()!=word2.length())
        return false;
    map<char, int> m1;
    map<char, int> m2;
    for (char c: word1)
        m1[c]++;
    for (char c: word2)
        m2[c]++;
    map<int, int> m3;
    map<int, int> m4;
    for (auto it: m1)
        m3[it.second]++;
    for (auto it: m2)
        m4[it.second]++;
    for (auto it: m3){
        if (m3[it.first] != m4[it.first])
            return false;
    for (auto it: m1)
        if (m2[it.first] == 0)
            return false;
    }
    return true;
}
};
