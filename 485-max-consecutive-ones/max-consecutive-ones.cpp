class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        long long num = 0;
        long long maxi = INT_MIN;
        int left = 0;
        while(left < n)
        {
            if(nums[left] == 1)
                num++;
            else
            {
                maxi = max(maxi, num);
                num = 0;
            }

            left++;
        }
        maxi = max(maxi, num);

        return maxi;
    }
};