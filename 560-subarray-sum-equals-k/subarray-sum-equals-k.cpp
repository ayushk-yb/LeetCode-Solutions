class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int currSum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int i = 0; i < n; i++)
        {
            currSum += nums[i];
            if(mp[currSum - k] > 0)
            {
                count += mp[currSum - k];
            }

            mp[currSum]++;
        }

        return count;
    }
};