class Solution {
public:
    int solve(int i, int j, int n1, int n2, string &s, string &t, vector<vector<int>> &dp){
        if(i == n1 || j == n2){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == t[j]){
            return dp[i][j] = 1 + solve(i + 1, j + 1, n1, n2, s, t, dp);
        }
        else{
            return dp[i][j] = max(solve(i + 1, j, n1, n2, s, t, dp), solve(i, j + 1, n1, n2, s, t, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return solve(0, 0, n1, n2, text1, text2, dp);
    }
};