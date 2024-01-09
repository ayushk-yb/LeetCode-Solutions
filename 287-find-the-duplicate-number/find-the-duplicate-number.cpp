class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        // unordered_set<int> st;
        vector<bool> hash(n + 1, false);
        for(int i = 0; i <= n; i++)
        {
            if(hash[nums[i]])
                return nums[i];
            hash[nums[i]] = true;
        }
        return 0;
    }
};