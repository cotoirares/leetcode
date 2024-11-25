int trap(vector<int>& height) {
    int i = 0, j, final_quantity = 0;
    while (height[i] == 0 && i<height.size()-1) i++;
    while (i<height.size()-1){
        int current_quantity = 0, max_indices = -1;
        j = i + 1;
        while (height[i] > height[j]) {
            if (max_indices == -1 || height[j] >= height[max_indices])
                max_indices = j;
            if (j == height.size() - 1)
                break;
            else j++;
        }
        if (height[i] <= height[j]){
            for (int k = i; k<j; k++)
                current_quantity += height[i] - height[k];
            i = j;
        }
        else{
            for (int k = i+1; k<max_indices; k++)
                current_quantity += height[max_indices] - height[k];
            i = max_indices;
        }
        final_quantity += current_quantity;
    }
    return final_quantity;
}
