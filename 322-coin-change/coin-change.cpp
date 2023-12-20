class Solution {
public:
    int solve(int idx, int k, vector<int> &arr, vector<vector<int>> &dp)
    {
        if(idx == 0)
        {
            if(k % arr[idx] == 0)
                return k / arr[idx];
            
            return 1e9;
        }
        

        if (dp[idx][k] != -1)
            return dp[idx][k];

        int not_take = solve(idx - 1, k, arr, dp);
        int take = 1e9;
        if(arr[idx] <= k)
            take = 1 + solve(idx, k - arr[idx], arr, dp);

        return dp[idx][k] = min(take, not_take);
    }

    int coinChange(vector<int>& arr, int x) {
        int n = arr.size();
        vector<int> prev(x + 1, 1e8);

        for(int i = 0; i <= x; i++)
        {
            if(i % arr[0] == 0)
                prev[i] = i / arr[0];
        }

        for(int i = 1; i < n; i++)
        {
            vector<int> curr(x + 1, 1e8);
            for(int tar = 0; tar <= x; tar++)
            {
                int not_take = prev[tar];
                int take = 1e8;
                if(tar >= arr[i])
                    take = 1 + curr[tar - arr[i]];
                
                curr[tar] = min(take, not_take);
            }
            prev = curr;
        }

        int res = prev[x];
        return (res == 1e8) ? -1 : res;
    }
};
