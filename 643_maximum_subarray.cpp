class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    int max_sum = -INT_MAX, i = 0, j = k-1, current_sum = 0;
    while (j<nums.size()){
        if (i == 0) {
            for (i; i <= j; i++)
                current_sum += nums[i];
            i = 0;
        }
        else
            current_sum = current_sum - nums[i-1] + nums[j];
        if (current_sum > max_sum)
            max_sum = current_sum;
        i++;j++;
    }
    if (current_sum > max_sum)
        max_sum = current_sum;
    return (double) max_sum / k;
}
};
