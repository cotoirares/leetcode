bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    for (int i = 0; i<nums.size() - 2*k + 1; i++){
        bool ascending = true;
        for (int j = i+1; j<i+k; j++)
            if (nums[j] <= nums[j-1]){
                ascending = false;
                break;
            }
        for (int j = i+k+1; j<i+2*k; j++)
            if (nums[j] <= nums[j-1]){
                ascending = false;
                break;
            }
        if (ascending) return true;
    }
    return false;

