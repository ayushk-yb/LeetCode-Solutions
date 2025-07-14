# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def getDecimalValue(self, head):
        binaryString = ""
        curr = head
        n = 0

        while curr:
            binaryString += str(curr.val)
            curr = curr.next
            n += 1

        number = 0
        idx = 1
        while n > 0:
            number = number + idx * int(binaryString[n - 1])
            n -= 1
            idx *= 2
        
        return number