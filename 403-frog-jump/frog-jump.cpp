class Solution
{
    public:
        int solve(vector<int> &arr, int idx, int lastJump, vector<vector< int>> &dp)
        {
            if (idx == arr.size() - 1)
            {
                return 1;
            }

            if (dp[idx][lastJump] != -1)
            {
                return dp[idx][lastJump];
            }

            int n = arr.size();
            for (int jump = lastJump - 1; jump <= lastJump + 1; ++jump)
            {
                if (jump > 0)
                {
                    int nextIdx = idx;
                    while (nextIdx < n && arr[nextIdx] < arr[idx] + jump)
                    {
                        ++nextIdx;
                    }

                    if (nextIdx < n && arr[nextIdx] == arr[idx] + jump)
                    {
                        if (solve(arr, nextIdx, jump, dp) == 1)
                        {
                            dp[idx][lastJump] = 1;
                            return 1;
                        }
                    }
                }
            }

            dp[idx][lastJump] = 0;
            return 0;
        }

    bool canCross(vector<int> &stones)
    {
        int n = stones.size();
        if (stones[1] - stones[0] != 1)
            return false;

        vector<vector < int>> dp(n, vector<int> (n, -1));
        return solve(stones, 1, 1, dp) == 1;
    }
};