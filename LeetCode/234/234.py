# Definition for singly-linked list.
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

    def isPalindrome(self, head: ListNode) -> bool:
        num_nodes = self.count_nodes(head)
        stack = []
        act_node = head

        while len(stack) < num_nodes // 2:
            stack.append(act_node.val)
            act_node = act_node.next

        if num_nodes % 2 != 0:
            act_node = act_node.next

        while act_node != None:
            if act_node.val != stack.pop():
                break
            act_node = act_node.next

        return act_node == None