class Solution {
public:
    void solve(int i, int n, int target, vector<int>& arr, vector<int>& temp, vector<vector<int>>& res)
    {
        if(target == 0)
        {
            res.push_back(temp);
            return;
        }

        for(int idx = i; idx < n; idx++)
        {
            if(idx > i && arr[idx] == arr[idx - 1])
                continue;
            
            if(arr[idx] > target)
                break;
            
            temp.push_back(arr[idx]);
            solve(idx + 1, n, target - arr[idx], arr, temp, res);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        int n = arr.size();
        vector<int> temp;
        solve(0, n, target, arr, temp, res);
        return res;        
    }
};