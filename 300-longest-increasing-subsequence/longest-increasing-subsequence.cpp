class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> next(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            // vector<int> curr(n + 1, 0);
            for (int prev = i - 1; prev >= -1; prev--) {
                int pick = 0;
                if (prev == -1 || nums[i] > nums[prev]) {
                    pick = 1 + next[i + 1];
                }
                int not_pick = next[prev + 1];
                next[prev + 1] = max(pick, not_pick);
            }
            // next = curr;
        }

        return next[0];
    }
};
