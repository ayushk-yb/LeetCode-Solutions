import heapq

class Solution(object):
    def clearStars(self, s):
        """
        :type s: str
        :rtype: str
        """
        priority_queue = []
        n = len(s)
        invalid_indexes = [False] * n

        for idx, ch in enumerate(s):
            if ch == '*':
                invalid_indexes[idx] = True
                _, inv_idx = heapq.heappop(priority_queue)
                invalid_indexes[-inv_idx] = True
            
            else:
                heapq.heappush(priority_queue, (ch, -idx))
        
        res = ""
        for i in range(n):
            if not invalid_indexes[i]:
                res += s[i]
        
        return res


        