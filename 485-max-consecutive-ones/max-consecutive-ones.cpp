class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int curr = 0, currAnd = 1;
        for(int i = 0; i < n; i++){
            currAnd = currAnd & nums[i];
            if(currAnd == 1){
                curr++;
            }
            else{
                ans = max(ans, curr);
                curr = 0;
                currAnd = 1;
            }
        }

        ans = max(ans, curr);
        return ans;
    }
};