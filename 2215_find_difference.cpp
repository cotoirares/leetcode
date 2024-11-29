class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> answer;
    map<int, int> elems1;
    map<int, int> elems2;
    for (auto it: nums1)
        elems1[it]++;
    for (auto it: nums2)
        elems2[it]++;
    vector<int> ans1;
    vector<int> ans2;
    for (auto it: elems1)
        if (!elems2[it.first])
            ans1.push_back(it.first);
    for (auto it: elems2)
        if (!elems1[it.first])
            ans2.push_back(it.first);
    answer.push_back(ans1);
    answer.push_back(ans2);
    return answer;
}

};
