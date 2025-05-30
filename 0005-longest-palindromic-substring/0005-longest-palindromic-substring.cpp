class Solution {
public:
    string longestCommonSubstring(string text1, string text2)
    {
        int l1 = text1.length(), l2 = text2.length();
        vector<int> prev(l2 + 1, 0);
        int maxLength = 0, endIndex = 0;
        for (int i = 1; i <= l1; i++)
        {
            // vector<int> curr(l2 + 1, 0);
            int last = 0;
            for (int j = 1; j <= l2; j++)
            {
                int temp = prev[j];
                if (text1[i - 1] == text2[j - 1])
                {
                    prev[j] = 1 + last;
                    
                    // Update maxLength and endIndex for palindromic substring
                        if (prev[j] > maxLength && i - prev[j] + 1 == l1 - j) {
                            maxLength = prev[j];
                            endIndex = i - 1;
                        }
                }
                else
                {
                    prev[j] = 0;
                }

                last = temp;
            }
        }
        return text1.substr(endIndex - maxLength + 1, maxLength + 1);
    }

    string longestPalindrome(string s)
    {
        if(s.length() == 1)
            return s;
        string rev = s;
        reverse(rev.begin(), rev.end());
        return longestCommonSubstring(s, rev);
    }
};