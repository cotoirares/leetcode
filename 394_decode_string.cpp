class Solution {
public:
    bool integer(char c){
        return c >= '0' && c <= '9';
    }

    int get_factor(string factor){
        int number = 0;
        reverse(factor.begin(), factor.end());
        for (char c : factor) {
            number = number * 10 + (c - '0');
        }
        return number;
    }

    string decodeString(string s) {
        stack<char> st;
        int open_brack = 0;
        string result = "";
        string curr_string = "";
        for (char c: s){
            if (open_brack == 0 && integer(c)){
                if (!curr_string.empty()) {
                    result += curr_string;
                    curr_string = "";
                }
            }
            if (open_brack == 0 && !integer(c) && c != '[' && c != ']') {
                curr_string += c;
                continue;
            }
            if (c == '[') {
                open_brack++;
                st.push(c);
            }
            else if (c == ']'){
                open_brack--;
                string factor="", aux="";
                if (open_brack == 0){
                    while (!st.empty() && st.top()!='[') {
                        aux += st.top();
                        st.pop();
                    }
                    st.pop(); // Pop the '['
                    while (!st.empty() && integer(st.top())){
                        factor += st.top();
                        st.pop();
                    }
                    int mul_factor = get_factor(factor);
                    reverse(aux.begin(), aux.end());
                    string temp = "";
                    while (mul_factor--)
                        temp += aux;
                    result += temp;
                }
                else{
                    while (!st.empty() && st.top()!='[') {
                        aux += st.top();
                        st.pop();
                    }
                    st.pop(); // Pop the '['
                    while (!st.empty() && integer(st.top())){
                        factor += st.top();
                        st.pop();
                    }
                    int mul_factor = get_factor(factor);
                    reverse(aux.begin(), aux.end());
                    string temp = "";
                    while (mul_factor--) {
                        temp += aux;
                    }
                    for (char x : temp)
                        st.push(x);
                }
            }
            else {
                st.push(c);
            }
        }
        if (!curr_string.empty()) {
            result += curr_string;
        }
        string aux="";
        while (!st.empty()) {
            aux += st.top();
            st.pop();
        }
        if (!aux.empty()) {
            reverse(aux.begin(), aux.end());
            result += aux;
        }
        return result;
    }
};

