class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> elems;
        for (auto it: arr)
            elems[it]++;
        map<int, int> occ;
        for (auto it: elems)
            if (occ[it.second] == 0)
                occ[it.second]++;
            else return false;
        return true;
    }
};
