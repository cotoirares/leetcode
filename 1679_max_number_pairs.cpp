class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
    map<int, int> numbers;
    int pairs = 0;
    for (auto it: nums)
        numbers[it]++;
    for (auto it: nums){
        if (numbers[k-it] != 0) {
            if (it != k-it) {
                int no_pairs = min(numbers[it], numbers[k - it]);
                pairs += no_pairs;
                numbers[it] -= no_pairs;
                numbers[k - it] -= no_pairs;
            }
            else{
                int no_pairs = numbers[it] / 2;
                pairs += no_pairs;
                numbers[it] -= 2*no_pairs;
            }
        }
    }
    return pairs;
}

};
