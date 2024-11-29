class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int, int> m1;
        for (auto it: nums)
            m1[it]++;
        int target = nums.size() - k + 1;
        for (auto it : m1){
            if (it.second >= target)
                return it.first;
            else target -= it.second;
        } 
        return 0; 
    }
};
