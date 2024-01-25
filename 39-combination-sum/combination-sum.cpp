class Solution {
public:
    void solve(int i, int n, int target, vector<int>& arr, vector<int>& temp, vector<vector<int>>& res)
    {
        if(i == n)
        {
            if(target == 0)
                res.push_back(temp);
            
            return;
        }

        if(arr[i] <= target)
        {
            temp.push_back(arr[i]);
            solve(i, n, target - arr[i], arr, temp, res);
            temp.pop_back();
        }

        solve(i + 1, n, target, arr, temp, res);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> res;
        int n = arr.size();
        vector<int> temp;
        solve(0, n, target, arr, temp, res);
        return res;
    }
};