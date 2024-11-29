class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int counter = 0;
    for (int i = 0; i<nums.size();i++)
        if (nums[i] == 0){
            nums.erase(nums.begin() + i);
            counter++;
            i--;
        }
    while (counter--)
        nums.push_back(0);
}
};
