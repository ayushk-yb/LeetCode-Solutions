class Solution {
    public int majorityElement(int[] nums) {
        int candidate = 0, count = 0;
        int n = nums.length;
        int i = 0;
        while(i < n){
            if(count == 0){
                candidate = nums[i];
            }
            if(nums[i] == candidate){
                count++;
            }
            else{
                count--;
            }
            i++;
        }

        return candidate;
    }
}