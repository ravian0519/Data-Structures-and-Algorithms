""" 
Problem no. 21:
Merge Two Sorted Lists.
Merge two sorted linked lists and return it as a sorted list. 
The list should be made by splicing together the nodes of the first two lists.
LINK: https://leetcode.com/problems/merge-two-sorted-lists/
"""


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        if not l1 and not l2:
            return None
        temp1 = l1
        temp2 = l2
        root = ListNode()
        result = root
        while temp1 and temp2:
            if temp1.val <= temp2.val:
                result.val = temp1.val
                result.next = ListNode()
                result = result.next
                temp1 = temp1.next
            else:
                result.val = temp2.val
                result.next = ListNode()
                result = result.next
                temp2 = temp2.next
        while temp1:
            result.val = temp1.val
            if temp1.next:
                result.next = ListNode()
                result = result.next
            temp1 = temp1.next
        while temp2:
            result.val = temp2.val
            if temp2.next:
                result.next = ListNode()
                result = result.next
            temp2 = temp2.next
        print(result.val)
        result = None
        return root