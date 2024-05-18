class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakPoint = -1;
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                breakPoint = i;
                break;
            }
        }

        if(breakPoint == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        int pivot = breakPoint;
        while(pivot < n - 1){
            if(nums[pivot + 1] > nums[breakPoint]){
                pivot++;
            }
            else{
                break;
            }
        }

        swap(nums[pivot], nums[breakPoint]);
        reverse(nums.begin() + breakPoint + 1, nums.end());
        return;
    }
};