class Solution {
public:
    int countPartitions(int n, int d, vector<int> &arr) {
        int totalSum = 0;
        for(int i = 0; i < n; i++)
        {
            totalSum += arr[i];
        }

        int diff = totalSum - d;
        if(diff % 2 != 0 || diff < 0)
            return 0;
        
        int k = diff / 2;

        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        if(arr[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;
        
        if(arr[0] != 0 && arr[0] <= k)
            dp[0][arr[0]] = 1;

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= k; j++)
            {
                int not_take = dp[i - 1][j];
                int take = 0;
                if(arr[i] <= j)
                    take = dp[i - 1][j - arr[i]];
                
                dp[i][j] = (take + not_take);
            }
        }

        return dp[n - 1][k];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(), target, nums);
    }
};