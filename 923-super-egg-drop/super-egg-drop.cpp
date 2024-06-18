class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

        for (int i = 1; i <= n; i++) {
            dp[i][1] = i;
        }
        for (int j = 1; j <= k; j++) {
            dp[0][j] = 0;
            dp[1][j] = 1;
        }

        for(int i = 2; i <= n; i++){
            for(int j = 2; j <= k; j++){
                int mini = 1e9;
                int floor = 1, high = i;
                while(floor <= high){
                    int mid = (floor + high) / 2;
                    int willBreak = dp[mid - 1][j - 1];
                    int notBreak = dp[i - mid][j];
                    if (willBreak > notBreak) {
                        high = mid - 1;
                    } else {
                        floor = mid + 1;
                    }
                    int temp = 1 + max(willBreak, notBreak);
                    mini = min(mini, temp);                    
                }    
                dp[i][j] = mini;            
            }
        }

        return dp[n][k];
    }
};