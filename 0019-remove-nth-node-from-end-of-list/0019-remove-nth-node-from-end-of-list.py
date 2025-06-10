# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: Optional[ListNode]
        :type n: int
        :rtype: Optional[ListNode]
        """
        size = 0
        curr = head
        while curr:
            curr = curr.next
            size += 1

        curr = head
        if size == n:
            return curr.next

        n = size - n
        while n > 1:
            curr = curr.next
            n -= 1
        
        curr.next = curr.next.next

        return head
        