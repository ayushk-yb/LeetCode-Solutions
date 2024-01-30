class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int mid = (high + low) / 2;

        
        while(low < high)
        {
            if(mid % 2 != 0)
                mid = mid - 1;
            if(nums[mid] == nums[mid + 1])
            {
                low = mid + 2;
            }
            else
            {
                high = mid;
            }

            mid = (high + low) / 2;
        }

        return nums[low];
    }
};