class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        answer = []

        n = len(nums)
        for i in range(n):
            if i > 0 and nums[i - 1] == nums[i]:
                continue
            
            for j in range(i + 1, n):
                if j > i + 1 and nums[j - 1] == nums[j]:
                    continue
                
                left, right = j + 1, n - 1
                localTarget = target - (nums[i] + nums[j])

                while left < right:
                    currSum = nums[left] + nums[right]

                    if currSum == localTarget:
                        answer.append([nums[i], nums[j], nums[left], nums[right]])

                        left += 1
                        right -= 1

                        while left < right and nums[left - 1] == nums[left]:
                            left += 1
                        
                        while left < right and nums[right + 1] == nums[right]:
                            right -= 1
                    
                    elif currSum < localTarget:
                        left += 1
                    
                    else:
                        right -= 1
        
        return answer
        