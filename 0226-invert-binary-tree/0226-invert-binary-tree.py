# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def invertHelper(self, node):
        if not node:
            return

        temp = node.left
        node.left = node.right
        node.right = temp

        self.invertHelper(node.left)
        self.invertHelper(node.right)

    def invertTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """
        if not root:
            return
        
        self.invertHelper(root)

        return root
        
