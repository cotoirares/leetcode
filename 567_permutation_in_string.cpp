class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length())
        return false;
    unordered_map<char, int> m1;
    unordered_map<char, int> m2;

    for (char c: s1)
        m1[c]++;

    int i = 0, j = s1.length()-1;
    for (int k = i; k<=j;k++)
        m2[s2[k]]++;

    while (j<s2.length()){
        // compare the maps
        bool ok = 1;
        for (auto& l: m1){
            if (m2[l.first] != l.second) {
                ok = 0;
                break;
            }
        }
        if (ok)
            return true;

        m2[s2[i]]--;
        if (j < s2.length())
            m2[s2[j+1]]++;
        i++, j++;
    }
    return false;
}
};
