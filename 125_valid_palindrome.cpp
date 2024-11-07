class Solution {
public:
    bool inRange(char c){
    if (!(('0'<= c && c<='9') || ('A'<=c && c<='Z') || ('a'<=c && c<='z')))
        return false;
    return true;
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;
        while (i<=j){
            if (!inRange(s[i]))
                i++;
            else if (!inRange(s[j]))
                j--;
            else if (tolower(s[i])!=tolower(s[j])) return false;
            else i++, j--;
        }
    return true;
    }
};
