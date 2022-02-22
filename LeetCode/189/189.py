class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        temp = [0]*len(nums)
        k = k%len(nums)
        for i in range(len(nums)):
          temp[(i+k)%(len(nums))] = nums[i]
        for i in range(len(nums)):
          nums[i] = temp[i]

_ = Solution()
_.rotate([1,2,3,4,5,6,7], 3)
_.rotate([-1,-100,3,99], 2)
_.rotate([0, 1], 10)

        