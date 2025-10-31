class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        freq = [0] * 100

        for num in nums:
            freq[num] += 1
        
        res = []
        for i in range(0, 100):
            if freq[i] == 2:
                res.append(i)
        
        return res