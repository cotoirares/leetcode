int romanToInt(string s) {
    unordered_map<char, int> hash_map = {{'I', 1}, {'V', 5}, {'X', 10},
                                         {'L', 50}, {'C', 100}, {'D', 500},
                                         {'M', 1000}};
    int i = 0, j = 1, number = 0;
    while (j < s.length()){
        if (hash_map[s[i]] < hash_map[s[j]]){
            number+=(hash_map[s[j]] - hash_map[s[i]]);
            i+=2;
            j+=2;
        }
        else{
            number+=hash_map[s[i]];
            i++;
            j++;
        }
    }
    number+=hash_map[s[i]];
    return number;
}
