# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[List[int]]
        """
        if not root:
            return []
        
        level_order = []
        queue = deque([[root]])
        
        while queue:
            curr_node_level = queue.popleft()
            next_level = []
            curr_level_order = []
            for curr_node in curr_node_level:
                curr_level_order.append(curr_node.val)

                if curr_node.left:
                    next_level.append(curr_node.left)
                
                if curr_node.right:
                    next_level.append(curr_node.right)
            
            queue.append(next_level) if next_level else None
            level_order.append(curr_level_order)

        return level_order
