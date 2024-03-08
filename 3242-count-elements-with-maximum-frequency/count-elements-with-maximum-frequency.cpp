class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans = 0;
        vector<int> count(101, 0);
        int maxFreq = INT_MIN;
        for(int num : nums)
        {
            count[num]++;
        }

        for(int num : count)
        {
            maxFreq = max(maxFreq, num);
        }

        for(int num : nums)
        {
            if(count[num] == maxFreq)
                ans++;
        }

        return ans;
    }
};