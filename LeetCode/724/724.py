from LeetCode.test_framework import test


class Solution:
    def sum(nums: list[int]):
        res = 0
        for num in nums:
            res += num
        return res

    def pivotIndex(self, nums: list[int]) -> int:
        right_sum, left_sum = Solution.sum(nums), 0
        for i in range(len(nums)):
            right_sum -= nums[i]
            left_sum += nums[i - 1] if i > 0 else 0
            if right_sum == left_sum:
                return i

        return -1


inputs = [[1, 7, 3, 6, 5, 6], [1, 2, 3], [2, 1, -1]]
truth = [3, -1, 0]
_ = Solution()

test(inputs, truth, _.pivotIndex)