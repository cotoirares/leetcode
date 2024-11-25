class Solution {
public:
    #define MAX 1000000007
    int sumOfGoodSubsequences(vector<int>& nums) {
    long dp[100001] = {0};
    long sums[100001] = {0};
    for (auto it: nums){
        dp[it]  = (dp[it] + 1) % MAX;
        sums[it] = (sums[it] + it) % MAX;

        if (it - 1 >= 0 && dp[it-1] > 0){
            dp[it] = (dp[it] + dp[it-1]) % MAX;
            sums[it] = (sums[it] + sums[it-1] + (dp[it-1]*it)%MAX)%MAX;
        }
        if (it + 1 < 100001 && dp[it+1] > 0){
            dp[it] = (dp[it] + dp[it+1])%MAX;
            sums[it] = (sums[it] + sums[it+1] + (dp[it+1]*it)%MAX)%MAX;
        }
    }
    long answer = 0;
    for (int i = 0; i<100001; i++){
        answer = (answer + sums[i])%MAX;
    }
    return (int) answer;
}
};
