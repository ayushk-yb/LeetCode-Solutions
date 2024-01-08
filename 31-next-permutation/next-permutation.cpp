class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int brk_pt = -1;
       int n = nums.size();
       for(int i = n - 2; i >= 0; i--)
       {
           if(nums[i] < nums[i + 1])
           {
               brk_pt = i;
               break;
           }
       }
       if(brk_pt == -1)
       {
           reverse(nums.begin(), nums.end());
           return;
       }
        int i = brk_pt;
        while(i < n - 1)
        {
            if(nums[i + 1] > nums[brk_pt])
            {
                i++;
            }
            else
            {
                break;
            }
        }
       swap(nums[i], nums[brk_pt]);
       reverse(nums.begin() + brk_pt + 1, nums.end());
    }
};