class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(height)
        left, right = 0, n - 1
        maxArea = 0

        while left < right:
            width = right - left
            if height[left] < height[right]:
                maxArea = max(maxArea, height[left] * width)
                left += 1
            else:
                maxArea = max(maxArea, height[right] * width)
                right -= 1
        
        return maxArea