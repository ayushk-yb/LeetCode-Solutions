class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n <= 0:
            return False
        
        # print(math.log(n), math.log(3))
        result = math.log10(n) / math.log10(3)
        # print(result)
        
        return math.floor(result) == result