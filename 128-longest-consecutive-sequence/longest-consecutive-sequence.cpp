class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        int count = 1, maxi = 0;
        for(int i = 0; i < n; i++)
        {
            int num = nums[i];
            if(mp[num - 1] == 0)
            {
                while(mp[num + 1] > 0)
                {
                    num += 1;
                    count += 1;
                }

                maxi = max(maxi, count);
                count = 1;
            }
        }

        return maxi;
    }
};