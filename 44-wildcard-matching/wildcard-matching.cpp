class Solution {
public:
    bool isMatch(string p, string s) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;
        for(int j = 1; j <= m; j++)
        {
            dp[0][j] = 0;
        }

        for(int i = 1; i <= n; i++)
        {   
            bool flag = true;
            for(int idx = 0; idx < i; idx++)
            {
                if(s[idx] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[i - 1] == p[j - 1] || s[i - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(s[i - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[n][m];
    }
};