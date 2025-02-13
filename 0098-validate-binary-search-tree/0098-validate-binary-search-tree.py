# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        curr = root
        inorder_prev = None
        while curr:
            if not curr.left:
                if inorder_prev is not None and inorder_prev >= curr.val:
                    return False
                
                inorder_prev = curr.val
                curr = curr.right
            else:
                pre = curr.left
                while pre.right and pre.right != curr:
                    pre = pre.right
                
                if not pre.right:
                    pre.right = curr
                    curr = curr.left
                else:
                    pre.right = None
                    if inorder_prev is not None and inorder_prev >= curr.val:
                        return False
                
                    inorder_prev = curr.val
                    curr = curr.right
        
        return True
        