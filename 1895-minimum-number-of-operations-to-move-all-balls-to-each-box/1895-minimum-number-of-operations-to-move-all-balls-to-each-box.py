class Solution(object):
    def minOperations(self, boxes):
        """
        :type boxes: str
        :rtype: List[int]
        """
        n = len(boxes)
        # oneIndex = [idx for idx in range(n) if boxes[idx] == '1']

        answer = [0] * n
        for i in range(n):
            curr_ans = 0
            for j in range(n):
                if boxes[j] == '1':
                    answer[i] += abs(j - i)
        
        return answer