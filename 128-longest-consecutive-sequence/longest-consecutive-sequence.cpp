class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }
        int count = 1, maxi = 0;
        for(int i = 0; i < n; i++)
        {
            int num = nums[i];
            if(st.find(num - 1) == st.end())
            {
                while(st.find(num + 1) != st.end())
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