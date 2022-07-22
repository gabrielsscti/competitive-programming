class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if head is None:
            return head

        actNode = head
        firstNodeEven = head.next
        lastNodeOdd = head
        count = 1
        while actNode != None:
            if count % 2 != 0:
                lastNodeOdd = actNode

            nextNode = actNode.next
            if actNode.next != None:
                actNode.next = actNode.next.next

            actNode = nextNode
            count += 1

        lastNodeOdd.next = firstNodeEven
        return head