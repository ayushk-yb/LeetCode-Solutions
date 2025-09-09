class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        ansArea = 0

        while left < right:
            width = right - left
            if height[left] < height[right]:
                ansArea = max(ansArea, width * height[left])
                left += 1
            else:
                ansArea = max(ansArea, width * height[right])
                right -= 1
        
        return ansArea