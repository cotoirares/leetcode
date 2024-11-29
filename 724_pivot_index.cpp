class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    vector<int> leftSums(nums.size(), 0);
    vector<int> rightSums(nums.size(), 0);
    for (int i = 1; i<nums.size(); i++)
        leftSums[i] = leftSums[i-1] + nums[i-1];
    for (int i = nums.size()-2;i>=0;i--)
        rightSums[i] = rightSums[i+1] + nums[i+1];
    for (int i = 0; i<nums.size(); i++)
        if (leftSums[i] == rightSums[i] )
            return i;
    return -1;
}
};
