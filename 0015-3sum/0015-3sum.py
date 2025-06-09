class Solution(object):
    def threeSum(self, nums):
        nums.sort()
        n = len(nums)

        answer = []

        for i in range(n):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            target = -nums[i]
            left, right = i + 1, n - 1

            while left < right:
                curr_sum = nums[left] + nums[right]

                if curr_sum == target:
                    answer.append([nums[i], nums[left], nums[right]])
                    left += 1
                    right -= 1

                    while left < right and nums[left - 1] == nums[left]:
                        left += 1
                    
                    while left < right and nums[right + 1] == nums[right]:
                        right -= 1
                    
                elif curr_sum < target:
                    left += 1
                else:
                    right -= 1
            
        return answer