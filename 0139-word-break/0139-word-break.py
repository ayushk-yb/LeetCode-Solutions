class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        dict_set = set(wordDict)
        n = len(s)
        dp = [False] * (n + 1)

        dp[0] = True
    
        for i in range(1, n + 1):
            for j in range(i):
                if dp[j] and s[j : i] in dict_set:
                    dp[i] = True
                    break
        
        return dp[n]
        