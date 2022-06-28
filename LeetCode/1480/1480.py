from LeetCode.test_framework import test


class Solution:
    def runningSum(self, nums: list[int]) -> list[int]:
        for i in range(1, len(nums)):
            nums[i] = nums[i - 1] + nums[i]

        return nums


_ = Solution()
inputs = [[1, 2, 3, 4], [1, 1, 1, 1, 1], [3, 1, 2, 10, 1]]
truth = [[1, 3, 6, 10], [1, 2, 3, 4, 5], [3, 4, 6, 16, 17]]

test(inputs, truth, _.runningSum)
