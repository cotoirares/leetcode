class Solution {
public:
    string defangIPaddr(string address) {
        string sol="";
        for (char c : address)
            if (c=='.')
                sol+="[.]";
            else sol+=c;
        return sol;
    }
};
