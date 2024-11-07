class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length()-1, j = num2.length()-1, carry = 0;
        std::string result = "";
        while (i>-1 || j>-1){
            int a = (i > -1 ? (num1[i] - '0') : 0);
            int b = (j > -1 ? (num2[j] - '0') : 0);
            int s = a + b + carry;
            result.append(to_string(s % 10));
            carry = s/10;
            i--; j--;
        }
        if (carry == 1) 
            result.append("1");
        reverse(result.begin(), result.end());
        return result;
    }
};
