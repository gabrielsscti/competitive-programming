class Solution:
  def moveZeroes(self, nums: list[int]) -> None:
    temp_arr   = []
    zero_count = 0
    for num in nums:
      if num == 0:
        zero_count += 1
      else:
        temp_arr.append(num)
    for i in range(len(temp_arr)):
      nums[i] = temp_arr[i]
    for i in range(len(temp_arr), len(nums)):
      nums[i] = 0
    
    print(nums)

_ = Solution()
_.moveZeroes([0,0,1])