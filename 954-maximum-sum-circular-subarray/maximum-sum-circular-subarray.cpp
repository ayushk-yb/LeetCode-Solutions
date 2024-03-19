class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        int maxi = -1e8;
        int currSum1 = 0, currSum2 = 0;
        int mini = 1e8;
        for(int i = 0; i < n; i++)
        {
            total += nums[i];
            currSum1 += nums[i];
            currSum2 += nums[i];
            maxi = max(maxi, currSum1);
            if(currSum1 < 0)
                currSum1 = 0;
            mini = min(mini, currSum2);
            if(currSum2 > 0)
                currSum2 = 0;
        }

        return total == mini ? maxi : max(maxi, total - mini);
    }
};