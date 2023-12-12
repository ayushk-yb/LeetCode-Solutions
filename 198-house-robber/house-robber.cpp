class Solution {
public:
    int solve(vector<int> &nums, int idx, vector<int> &dp)
    {
        if(dp[idx] != -1)
            return dp[idx];
        
        if(idx == 0)
            return nums[0];
        
        if(idx < 0)
            return 0;
        
        int take = INT_MIN;
        if(idx > 1)
            take = nums[idx] + solve(nums, idx - 2, dp);
        int not_take = solve(nums, idx - 1, dp);

        return dp[idx] = max(take, not_take);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        // return solve(nums, nums.size() - 1, dp);
        dp[0] = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            int take = nums[i];
            if(i > 1)
                take += dp[i - 2];
            
            int not_take = dp[i - 1];

            dp[i] = max(take, not_take);
        }

        return dp[nums.size() - 1];
    }
};
