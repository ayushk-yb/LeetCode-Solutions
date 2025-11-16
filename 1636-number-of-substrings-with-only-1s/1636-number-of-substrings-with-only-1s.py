class Solution:
    def numSub(self, s: str) -> int:
        MOD = 10**9 + 7
        current = 0
        ans = 0
        
        for ch in s:
            if ch == '1':
                current += 1
                ans = (ans + current) % MOD
            else:
                current = 0
        
        return ans