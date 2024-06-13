class Solution {
public:
    int solve(vector<int> &nums, int i, int target, int &n, int &sum, vector<vector<int>> &dp){
        if(i == n){
            if(target == 0){
                return 1;
            }
            return 0;
        }

        if(dp[i][target + sum] != -1){
            return dp[i][target + sum];
        }

        return dp[i][target + sum] = solve(nums, i + 1, target + nums[i], n, sum, dp) +
                solve(nums, i + 1, target - nums[i], n, sum, dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if(abs(target) > sum){
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(target + 2 * sum + 1, -1));

        return solve(nums, 0, target, n, sum, dp);
    }
};