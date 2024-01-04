class Solution {
public:
    bool isPalindrome(int i, int j, string &s)
    {
        while(i <= j)
        {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }
    int solve(int i, int n, string &s, vector<int> &dp)
    {
        if(i == n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];

        int minCuts = 1e8;
        for(int k = i; k < n; k++)
        {
            if(isPalindrome(i, k, s))
            {
                int cuts = 1 + solve(k + 1, n, s, dp);
                minCuts = min(minCuts, cuts);
            }
        }

        return dp[i] = minCuts;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return solve(0, n, s, dp) - 1;
    }
};