class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        // unordered_set<int> st;
        // vector<bool> hash(n + 1, false);
        int slow = nums[0], fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        fast = nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};