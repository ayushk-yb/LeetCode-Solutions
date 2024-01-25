class Solution {
public:
    void solve(int i, int n, vector<int> &nums, vector<vector<int>> &res, vector<int> &temp)
    {
        res.push_back(temp);
        for(int idx = i; idx < n; idx++)
        {
            if(idx != i && nums[idx] == nums[idx - 1])
                continue;
            
            temp.push_back(nums[idx]);
            solve(idx + 1, n, nums, res, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(0, n, nums, res, temp);

        return res;
    }
};