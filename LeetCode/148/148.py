# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def getMidNode(self, head: ListNode) -> ListNode:
        slow_ptr = head
        fast_ptr = head
        temp = head
        while fast_ptr is not None and fast_ptr.next is not None:
            temp = slow_ptr
            slow_ptr = slow_ptr.next
            fast_ptr = fast_ptr.next.next
        
        temp.next = None
        return slow_ptr

    def merge(self, left_node : ListNode, right_node : ListNode) -> ListNode:
        if left_node is None:
            return right_node
        elif right_node is None:
            return left_node

        act_left, act_right = left_node, right_node
        new_head = None
        if act_left.val < act_right.val:
            new_head = act_left
            act_left = act_left.next
        else:
            new_head = act_right
            act_right = act_right.next
        act_new = new_head
        while act_left is not None and act_right is not None:
            if act_left.val < act_right.val:
                act_new.next = act_left
                act_left = act_left.next
            else:
                act_new.next = act_right
                act_right = act_right.next

            act_new = act_new.next
        
        while act_left is not None:
            act_new.next = act_left
            act_left = act_left.next
            act_new = act_new.next
        
        while act_right is not None:
            act_new.next = act_right
            act_right = act_right.next
            act_new = act_new.next

        return new_head

    
    def sortList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head

        left_array, right_array = head, self.getMidNode(head)
        left_array = self.sortList(left_array)
        right_array = self.sortList(right_array)
        sorted = self.merge(left_array, right_array)
        return sorted
        

head = None       

act_node = head
while act_node is not None:
    print(act_node.val, end=" ")
    act_node = act_node.next
print()

_ = Solution()
head = _.sortList(head)

act_node = head
while act_node is not None:
    print(act_node.val, end=" ")
    act_node = act_node.next
print()