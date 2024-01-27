class Solution {
public:
    void solve(int i, int n, vector<int> &nums, vector<vector<int>> &res)
    {
        if(i == n)
        {
            // vector<int> temp;
            res.push_back(nums);

            return;
        }

        for(int idx = i; idx < n; idx++)
        {
            swap(nums[idx], nums[i]);
            solve(i + 1, n, nums, res);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        solve(0, n, nums, res);

        return res;
    }
};