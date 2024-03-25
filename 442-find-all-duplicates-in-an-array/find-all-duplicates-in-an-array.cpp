class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for(int i = 0; i < n; i++)
        {
            int absValue = abs(nums[i]);
            if(nums[absValue - 1] < 0)
                result.push_back(absValue);
            
            nums[absValue - 1] *= -1;
        }

        return result;
    }
};