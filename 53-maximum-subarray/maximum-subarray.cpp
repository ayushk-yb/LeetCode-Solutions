class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int S = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            S += nums[i];
            maxi = max(maxi, S);
            if(S < 0)
                S = 0;
        }

        return maxi;
    }
};