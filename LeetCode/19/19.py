class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def count_nodes(self, head: ListNode) -> int:
        count = 0
        while(head != None):
            head = head.next
            count += 1
        
        return count

    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        num_nodes = self.count_nodes(head)
        if n == num_nodes:
            return head.next

        count_nodes = 0
        act_node = head

        while num_nodes - n > count_nodes:
            if count_nodes + 1 == num_nodes - n:
                break
            act_node = act_node.next
            count_nodes += 1

        act_node.next = act_node.next.next
        return head


