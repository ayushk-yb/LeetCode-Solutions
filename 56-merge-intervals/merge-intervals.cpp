class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0], end = intervals[0][1];
        int i = 1;
        int n = intervals.size();
        while(i < n){
            if(end >= intervals[i][0]){
                if(end < intervals[i][1]){
                    end = intervals[i][1];
                }
                i++;
            }
            else{
                merged.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        merged.push_back({start, end});
        return merged;
    }
};