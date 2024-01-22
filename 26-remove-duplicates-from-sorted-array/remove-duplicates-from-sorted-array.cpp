class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 1;
        int ans = 1;
        int left = 0, right = 1;
        while(right < n)
        {
            if(nums[left] == nums[right])
            {
                right++;
            }
            else
            {
                nums[++left] = nums[right++];
                ans++;
            }
        }

        return ans;
    }
};