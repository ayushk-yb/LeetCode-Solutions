class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int prev = i - 1; prev >= -1; prev--) {
                int pick = 0;
                if (prev == -1 || nums[i] > nums[prev]) {
                    pick = 1 + dp[i + 1][i + 1];
                }
                int not_pick = dp[i + 1][prev + 1];
                dp[i][prev + 1] = max(pick, not_pick);
            }
        }

        return dp[0][0];
    }
};
