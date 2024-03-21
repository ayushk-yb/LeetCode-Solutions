class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charMap(128, -1);
        int start = 0, end = 0;
        int maxi = 0;
        int n = s.length();
        while(end < n)
        {   
            char ch = s[end];
            if(charMap[ch] == -1 || charMap[ch] < start)
            {
                charMap[ch] = end;
                maxi = max(maxi, end - start + 1);
                end++;
            }
            else
            {
                start = charMap[ch] + 1;
            }
        }

        return maxi;
    }
};