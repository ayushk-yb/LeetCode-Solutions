class Solution(object):
    def numRescueBoats(self, people, limit):
        """
        :type people: List[int]
        :type limit: int
        :rtype: int
        """
        people.sort()
        n = len(people)
        if people[0] > limit // 2:
            return n
        
        left, right = 0, n - 1
        boats = 0
        while left <= right:
            if people[left] + people[right] <= limit :
                left += 1
            right -= 1
            boats += 1
        
        return boats
