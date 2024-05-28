class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<int> next(n2 + 1, 0);
        // return solve(0, 0, n1, n2, text1, text2, dp);

        for(int i = n1 - 1; i >= 0; i--){
            vector<int> curr(n2 + 1, 0);
            for(int j = n2 - 1; j >= 0; j--){
                if(text1[i] == text2[j]){
                    curr[j] = 1 + next[j + 1];
                }
                else{
                    curr[j] = max(next[j], curr[j + 1]);
                }
            }
            next = curr;
        }

        return next[0];
    }
};