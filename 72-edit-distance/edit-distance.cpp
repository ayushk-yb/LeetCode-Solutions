class Solution {
public:
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i < 0){
            return j + 1;
        }
        if(j < 0){
            return i + 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == t[j]){
            return dp[i][j] = solve(i - 1, j - 1, s, t, dp);
        }
        else{
            int replace = solve(i - 1, j - 1, s, t, dp);
            int insert = solve(i, j - 1, s, t, dp);
            int remove = solve(i - 1, j, s, t, dp);

            return dp[i][j] = 1 + min(replace, min(insert, remove));
        }
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if(n1 == 0 && n2 == 0){
            return 0;
        }
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return solve(n1 - 1, n2 - 1, word1, word2, dp);
    }
};