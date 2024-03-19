class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return nums[0];
        sort(nums.begin(), nums.end());
        if(nums[0] != nums[1])
            return nums[0];
        if(nums[n - 1] != nums[n - 2])
            return nums[n - 1];
        // int ans = 0;
        int i = 1;
        while(i < n)
        {
            if(nums[i] != nums[i - 1])
                return nums[i- 1];
            
            i = i + 3;
        }

        return -1;
    }
};