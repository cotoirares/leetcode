class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maximum = 0, index = 0;
        for (auto it: gain){
            index += it;
            if (index > maximum)
                maximum = index;
        }
        return maximum;
    }
};
