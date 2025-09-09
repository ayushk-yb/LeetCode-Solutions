class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        dp = [0] * (n + 1)
        dp[1] = 1
        MOD = 10 ** 9 + 7

        share = 0
        for day in range(2, n + 1):
            if day - delay >= 1:
                share = (share + dp[day - delay]) % MOD
            
            if day - forget >= 1:
                share = (share - dp[day - forget] + MOD) % MOD
            
            dp[day] = share
        
        result = 0
        for day in range(n - forget + 1, n + 1):
            if day >= 1:
                result = (result + dp[day]) % MOD

        return result
