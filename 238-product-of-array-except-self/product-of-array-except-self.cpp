class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long int prod = 1;
        bool foundZero = false;
        int countZero = 0;
        for(int num : nums)
        {
            if(num == 0)
            {
                foundZero = true;
                countZero++;
                continue;
            }
            prod = prod * num;
        }
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0 && countZero == 1)
            {
                ans.push_back(prod);
                continue;
            }
            if(foundZero)
                ans.push_back(0);
            else
                ans.push_back(prod / nums[i]);
        }

        return ans;
    }
};