class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<double> prev(m + 1, 0);
        prev[0] = 1;

        for(int i = 1; i <= n; i++)
        {
            double last = prev[0];
            for(int j = 1; j <= m; j++)
            {
                double temp = prev[j];
                if(s[i - 1] == t[j - 1])
                    prev[j] = last + prev[j];
                
                last = temp;
            }
        }

        return prev[m];
    }
};