# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[List[int]]
        """
        if not root:
            return []

        curr = root
        queue = deque([curr])
        dequeue = deque([])
        while queue:
            n = len(queue)
            level = []
            while n > 0:
                node = queue.popleft()
                n -= 1
                level.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            dequeue.appendleft(level)
        
        return list(dequeue)
            
            