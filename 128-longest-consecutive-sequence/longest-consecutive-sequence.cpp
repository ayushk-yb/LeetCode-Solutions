class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int n = nums.size();
        int currCount = 1, maxLength = 0;
        for(int i = 0; i < n; i++){
            int curr = nums[i];
            if(numSet.find(curr - 1) == numSet.end()){
                int j = 1;
                while(numSet.find(curr + j) != numSet.end()){
                    currCount++;
                    j++;
                }

                maxLength = max(maxLength, currCount);
                currCount = 1;
            }
        }

        return maxLength;
    }
};