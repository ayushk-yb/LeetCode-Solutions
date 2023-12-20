class Solution {
public:
    //refer to coin change 1 solution first
    int change(int x, vector<int>& arr) {
        int n = arr.size();
        vector<int> prev(x + 1, 0);

        for(int i = 0; i <= x; i++)
        {
            if(i % arr[0] == 0)
                prev[i] = 1;
        }

        for(int i = 1; i < n; i++)
        {
            vector<int> curr(x + 1, 0);
            for(int tar = 0; tar <= x; tar++)
            {
                int not_take = prev[tar];
                int take = 0;
                if(tar >= arr[i])
                    take = curr[tar - arr[i]];
                
                curr[tar] = take + not_take;
            }
            prev = curr;
        }

        return prev[x];
    }
};