class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int k = 0;
        for(int i = 0; i < n; i++)
        {
            k += arr[i];
        }

        if(k % 2 == 0)
            k = k / 2;
        else
            return false;

        vector<bool> prev(k + 1, false);
        vector<bool> curr(k + 1, false);

        prev[0] = curr[0] = true;

        if(arr[0] <= k) 
            prev[arr[0]] = true;

        for(int i = 1; i < n; i++)
        {
            for(int tar = 1; tar <= k; tar++)
            {
                bool not_take = prev[tar];
                bool take = false;

                if(tar >= arr[i])
                    take = prev[tar - arr[i]];
                
                curr[tar] = take | not_take;
            }
            prev = curr;
        }

        return prev[k];
    }
};