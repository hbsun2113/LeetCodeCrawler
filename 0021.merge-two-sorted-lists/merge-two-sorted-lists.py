#大水题！！！
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        newhead=ListNode(-100)
        result=newhead
        while l1!=None and l2!=None :
            print (l1.val,l2.val)
            if l1.val<l2.val :
                newhead.next=ListNode(l1.val)
                newhead=newhead.next
                l1=l1.next
                #print (1)
                continue
            else :
                newhead.next=ListNode(l2.val)
                newhead=newhead.next
                l2=l2.next
                #print (1)
                
                
        if l1!=None:
            newhead.next=l1
        elif l2!=None:
            newhead.next=l2
            
            
        return result.next
        
        
        
        
        
        