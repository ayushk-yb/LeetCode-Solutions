class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        // return solve(0, k, n, arr, dp);
        for(int i = n - 1; i >= 0; i--)
        {
            int maxEle = INT_MIN, maxAns = INT_MIN, len = 0;
            for(int j = i; j < min(n, i + k); j++)
            {
                maxEle = max(maxEle, arr[j]);
                len++;
                int sum = (maxEle * len) + dp[j + 1];
                maxAns = max(maxAns, sum);
            }         
            dp[i] = maxAns;   
        }

        return dp[0];
    }
};