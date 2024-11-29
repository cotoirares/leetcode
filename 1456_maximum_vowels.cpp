class Solution {
public:
    int maxVowels(string s, int k) {
    map<char, bool> vowel;
    for (char c: s){
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vowel[c] = true;
        else vowel[c] = false;
    }
    int i = 0, j = k - 1, max_vowels = 0, current_vowels = 0;
    while (j<s.length()){
        if (i == 0){
            for (i;i<=j;i++)
                if (vowel[s[i]])
                    current_vowels++;
            i = 0;
        }
        else{
            if (vowel[s[i-1]])
                current_vowels--;
            if (vowel[s[j]])
                current_vowels++;
        }
        if (current_vowels > max_vowels)
            max_vowels = current_vowels;
        i++;j++;
    }
    if (current_vowels > max_vowels)
        max_vowels = current_vowels;
    return max_vowels;
}

};
