class Solution {
public:
    bool check_prefix(string target, string candidate){
        string current_string = "";
        while (current_string.length() < target.length())
            current_string += candidate;
        return target.compare(current_string) == 0;
    }

string gcdOfStrings(string str1, string str2) {
    string valid="", current_prefix="";
    int i = 0, min_length = min(str1.length(), str2.length());
    for (i = 0; i < min_length;i++){
        if (str1[i] == str2[i]){
            current_prefix+=str1[i];
            if (check_prefix(str1, current_prefix) && check_prefix(str2, current_prefix))
                if (valid.length() < current_prefix.length())
                    valid = current_prefix;
        }
        else current_prefix = "";
    }
    return valid;
}
};
