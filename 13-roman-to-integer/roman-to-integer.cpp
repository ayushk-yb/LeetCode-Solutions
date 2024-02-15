class Solution {
public:
    int romanToInt(string s) {
        vector<int> romanValues(128, 0); 
        romanValues['I'] = 1;
        romanValues['V'] = 5;
        romanValues['X'] = 10;
        romanValues['L'] = 50;
        romanValues['C'] = 100;
        romanValues['D'] = 500;
        romanValues['M'] = 1000;
        int num = 0;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            if(i + 1 < n && romanValues[s[i]] < romanValues[s[i + 1]])
            {
                num -= romanValues[s[i]];
            }
            else
            {
                num += romanValues[s[i]];
            }
        }

        return num;
    }
};