#大水题，注意是n是从后往前数的


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if head.next==None:
            return []
        
        length=1
        tmpp=head
        while tmpp.next!=None:
            length+=1
            tmpp=tmpp.next
        if length==n:
            head=head.next
            return head
        n=length-n+1
        print (length)
        tmp=head
        index=1
        while index<n-1:
            index+=1
            tmp=tmp.next
        if tmp.next!=None:
            tmp.next=tmp.next.next
            
        
        return head