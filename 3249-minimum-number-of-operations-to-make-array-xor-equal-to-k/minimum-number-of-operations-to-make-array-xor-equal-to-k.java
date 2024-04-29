class Solution {
    public int minOperations(int[] nums, int k) {
        int arrXor = 0;
        int n = nums.length;
        for(int i = 0; i < n; i++){
            arrXor = arrXor ^ nums[i];
        }

        if(arrXor == k){
            return 0;
        }
        int count = 0;
        while(arrXor > 0 || k > 0){
            if((arrXor % 2) != (k % 2)){
                count++;
            }

            arrXor /= 2;
            k /= 2;
        }

        return count;
    }
}