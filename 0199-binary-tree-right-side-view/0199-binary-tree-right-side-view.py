# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        if not root:
            return []
            
        level_order = []
        queue = [root]

        while queue:
            n = len(queue)
            curr_level = []
            for _ in range(n):
                curr = queue.pop(0)
                curr_level.append(curr.val)
                
                if curr.left:
                    queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)
            level_order.append(curr_level)
        
        ans = []
        for level in level_order:
            ans.append(level[-1])
        
        return ans