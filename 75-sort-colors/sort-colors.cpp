class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for(int i = 0; i < n; i++)
        {
            if(mp[0] != 0)
            {
                nums[i] = 0;
                mp[0]--;
            }
            else if(mp[1] != 0)
            {
                nums[i] = 1;
                mp[1]--;
            }
            else
            {
                nums[i] = 2;
                mp[2]--;
            }
        }
    }
};