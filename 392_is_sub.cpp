bool isSubsequence(string s, string t) {
    queue<char> letters;
    while (!s.empty()){
        letters.push(s[s.size()-1]);
        s.erase(s.size()-1);
    }
    while (!letters.empty() && !t.empty()){
        if (t[t.size()-1] == letters.front())
            letters.pop();
        
    }
}
