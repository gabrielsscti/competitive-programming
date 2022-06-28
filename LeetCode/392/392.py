from LeetCode.test_framework import test


class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if s == t or len(s) == 0:
            return True

        s_pos = 0
        for i in range(len(t)):
            if s[s_pos] == t[i]:
                s_pos += 1
            if s_pos == len(s):
                return True
        return False


def adapter(item):
    _ = Solution()
    return _.isSubsequence(item[0], item[1])


inputs = [["abc", "ahbgdc"], ["axc", "ahbgdc"], ["", "ahbgc"], ["b", "c"], ["c", "c"], ["b", "abc"]]
truth = [True, False, True, False, True, True]
test(inputs, truth, adapter)
