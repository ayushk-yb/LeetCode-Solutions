class Solution(object):
    def numDecodings(self, s):

        dp = [-1] * (len(s) + 1)

        # def count_ways(idx):
        #     if idx == len(s):
        #         return 1
            
        #     if s[idx] == '0':
        #         return 0
            
        #     if dp[idx] != -1:
        #         return dp[idx]
            
        #     ways = count_ways(idx + 1)

        #     if idx + 1 < len(s) and 10 <= int(s[idx:idx + 2]) <= 26:
        #         ways += count_ways(idx + 2)
            
        #     dp[idx] = ways

        #     return dp[idx]
        
        n = len(s)
        dp[n] = 1

        for i in range(n - 1, -1, -1):
            if s[i] == '0':
                dp[i] = 0
            else:
                dp[i] = dp[i + 1]
                if i + 1 < n and 10 <= int(s[i:i + 2]) <= 26:
                    dp[i] += dp[i + 2]
        
        return dp[0]
        