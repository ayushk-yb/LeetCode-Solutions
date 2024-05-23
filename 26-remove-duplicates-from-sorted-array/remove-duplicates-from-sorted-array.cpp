class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 1;
        int n = nums.size();
        int ans = 1;
        while(right < n){
            if(nums[left] == nums[right]){
                right++;
            }
            else{
                nums[++left] = nums[right++];
                ans++; 
            }
        }

        return ans;
    }
};