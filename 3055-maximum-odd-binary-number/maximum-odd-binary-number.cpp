class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int oneCount = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
                oneCount++;
        }
        int i = 0;
        while(oneCount > 1)
        {
            s[i] = '1';
            oneCount--;
            i++;
        }
        while(i != n - 1)
        {
            s[i] = '0';
            i++;
        }
        s[n - 1] = '1';

        return s;
    }
};