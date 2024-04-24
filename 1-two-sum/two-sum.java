class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int n = nums.length;

        for(int i = 0; i < n; i++){
            mp.put(nums[i], i);
        }

        for(int i = 0; i < n; i++){
            int second = target - nums[i];
            if(mp.containsKey(second) && mp.get(second) != i){
                return new int[]{i, mp.get(second)};
            }
        }

        return new int[]{};
    }
}