class Solution:
  def search(self, nums: list[int], target: int) -> int:
    start = 0; end = len(nums)

    while(start<end):
      mid = (start+end)//2
      if nums[mid] == target:
        return mid
      elif target < nums[mid]:
        end = mid
      else:
        start = mid+1
    return -1

sol = Solution()
print(sol.search([-1, 0, 3, 5, 9, 12], 9))
print(sol.search([-1,0,3,5,9,12], 2))
      