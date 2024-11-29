class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int zerosCount = 0;
        int maxLength = 0;

        while (right < nums.size()) {
            // Include nums[right] in the window
            if (nums[right] == 0) {
                zerosCount++;
            }

            // Shrink the window if zeros exceed k
            while (zerosCount > k) {
                if (nums[left] == 0) {
                    zerosCount--;
                }
                left++;
            }

            // Calculate the maximum length
            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};
