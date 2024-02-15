class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string prefix = strs[0];
        int size = prefix.size();
        for(int i = 1; i < n; i++)
        {
            int j = 0;
            int currSize = strs[i].size();
            while(j < size && j < currSize && prefix[j] == strs[i][j])
            {
                j++;
            }
            prefix = prefix.substr(0, j);
            if(prefix.empty())
                return "";
        }

        return prefix;
    }
};