class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int left = 0, right = 0;
    int zerosCount = 0;
    int maxLength = 0;
    while (right < nums.size()) {
        if (nums[right] == 0) {
            zerosCount++;
        }
        while (zerosCount > 1) {
            if (nums[left] == 0) {
                zerosCount--;
            }
            left++;
        }
        maxLength = max(maxLength, right - left + 1);
        right++;
    }
    return maxLength - 1;
}

};
