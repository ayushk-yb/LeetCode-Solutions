class Solution(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        result = []

        def dfs(curr):
            if curr > n:
                return
            result.append(curr)

            for i in range(10):
                next_num = curr * 10 + i

                if next_num > n:
                    break
                
                dfs(next_num)
        
        for num in range(1, 10):
            dfs(num)
        
        return result
        

        
