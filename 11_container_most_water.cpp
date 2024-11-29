class Solution {
public:
    int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1, max_area = 0;
    while (i<=j){
        int current_area = (j - i) * min(height[i], height[j]);
        if (current_area > max_area)
            max_area = current_area;
        if (height[i] > height[j])
            j--;
        else i++;
    }
    return max_area;
}
};
