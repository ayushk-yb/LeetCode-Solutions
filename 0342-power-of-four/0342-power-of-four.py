class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n <= 0:
            return False
        
        result = math.log10(n) / math.log10(4)

        return result == math.floor(result)


        