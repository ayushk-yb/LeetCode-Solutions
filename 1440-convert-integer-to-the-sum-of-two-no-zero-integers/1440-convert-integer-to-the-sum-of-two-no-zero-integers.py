class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        def checkZero(n):
            while n > 0:
                # print(n)
                if n % 10 == 0:
                    return False
                n = n // 10
            return True

        for i in range(1, n):
            j = n - i
            if checkZero(i) and checkZero(j):
                return [i, j]
        
        return []
        