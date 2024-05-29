class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if(n1 == 0 && n2 == 0){
            return 0;
        }
        // vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        vector<int> prev(n2 + 1, 0);
        // for(int i = 0; i <= n1; i++){
        //     dp[i][0] = i;
        // }
        for(int j = 0; j <= n2; j++){
            prev[j] = j;
        }
        for(int i = 1; i <= n1; i++){
            // vector<int> curr(n2 + 1, 0);
            int last = prev[0];
            prev[0] = i; 
            for(int j = 1; j <= n2; j++){
                int temp = prev[j];
                if(word1[i - 1] == word2[j - 1]){
                    prev[j] = last;
                }
                else{
                   prev[j] = 1 + min(last, min(prev[j - 1], prev[j]));
                }
                last = temp;
            }
        }

        return prev[n2];
    }
};