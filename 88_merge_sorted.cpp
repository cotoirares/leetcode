class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
    vector<int> solution;
    while (i<m && j<n){
        if (nums1[i]<nums2[j]) {
            solution.push_back(nums1[i]);
            i++;
        }
        else if (nums1[i]>nums2[j]){
            solution.push_back(nums2[j]);
            j++;
        }
        else {
            solution.push_back(nums1[i]);
            solution.push_back(nums2[j]);
            i++, j++;
        }
    }
    while (i<m){
        solution.push_back(nums1[i]);
        i++;
    }
    while (j<n){
        solution.push_back(nums2[j]);
        j++;
    }
    nums1 = solution;
    }
};
