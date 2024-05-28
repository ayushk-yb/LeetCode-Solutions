class Solution {
public:
    int solve(int i, int prev, vector<int> &nums, vector<vector<int>> &dp){
        if(i == 0){
            if(prev == -1 || nums[i] < nums[prev]){
                return 1;
            }
            return 0;
        }

        if(dp[i][prev + 1] != -1){
            return dp[i][prev + 1];
        }

        int pick = -1e8;
        if(prev == -1 || nums[i] < nums[prev]){
            pick = 1 + solve(i - 1, i, nums, dp);
        }

        int not_pick = solve(i - 1, prev, nums, dp);

        return dp[i][prev + 1] = max(pick, not_pick);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(n - 1, -1, nums, dp);
    }
};