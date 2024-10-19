class Solution(object):
    def romanToInt(self, s):
        romanDict = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }

        n = len(s)
        ans = 0
        for i in range(n):
            if i+1 < n and romanDict[s[i]] < romanDict[s[i+1]]:
                ans -= romanDict[s[i]]
            else:
                ans += romanDict[s[i]]

        return ans