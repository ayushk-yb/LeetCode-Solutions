class Solution:
    def maxDistinctElements(self, nums: List[int], k: int) -> int:
        intervals = [(x - k, x + k) for x in nums]
        intervals.sort()

        used = set()
        current = float('-inf')

        for left, right in intervals:
            val = max(left, current + 1)
            if val <= right:
                used.add(val)
                current = val

        return len(used)