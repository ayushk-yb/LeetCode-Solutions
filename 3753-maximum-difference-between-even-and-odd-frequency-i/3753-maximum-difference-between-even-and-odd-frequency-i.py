class Solution(object):
    def maxDifference(self, s):
        """
        :type s: str
        :rtype: int
        """
        freqMap = Counter(s)
        values = freqMap.values()
        maxOddFreq = -float('inf')
        minEvenFreq = float('inf')

        for val in values:
            if val % 2 == 0:
                if val < minEvenFreq:
                    minEvenFreq = val
            else:
                if val > maxOddFreq:
                    maxOddFreq = val

        return maxOddFreq - minEvenFreq