from LeetCode.test_framework import test


class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        storage_forth = {}
        storage_back = {}
        for i in range(len(s)):
            if s[i] in storage_forth and (storage_forth[s[i]] != t[i]):
                return False
            if t[i] in storage_back and (storage_back[t[i]] != s[i]):
                return False

            storage_forth[s[i]] = t[i]
            storage_back[t[i]] = s[i]
        return True




def adapter(item):
    _ = Solution()
    return _.isIsomorphic(item[0], item[1])

inputs = [['egg', 'add'], ['foo', 'bar'], ['paper', 'title'], ['badc', 'baba']]
truth = [True, False, True, False]

test(inputs, truth, adapter)