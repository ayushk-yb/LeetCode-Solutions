class Solution:
    def findLucky(self, arr: List[int]) -> int:
        freqMap = Counter(arr)
        
        maxValue = -1

        for num, freq in freqMap.items():
            if num == freq:
                maxValue = max(maxValue, num)

        return maxValue