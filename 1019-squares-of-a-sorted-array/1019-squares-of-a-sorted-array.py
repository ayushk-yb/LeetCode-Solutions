class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        left, right, resIdx = 0, n - 1, n - 1

        results = [0] * n

        while left <= right:
            if abs(nums[left]) < abs(nums[right]):
                results[resIdx] = nums[right] * nums[right]
                right -= 1
            else:
                results[resIdx] = nums[left] * nums[left]
                left += 1
            
            resIdx -= 1
        
        return results
