class Solution:
    def searchInsert(self, nums: list[int], target: int) -> int:
        start = 0
        end = len(nums)

        while(start < end):
            mid = (start+end)//2
            if nums[mid] == target:
                return mid
            elif target < nums[mid]:
                end = mid
            else:
                start = mid+1
        if target < nums[mid]:
          return mid
        else: 
          return mid+1 


sol = Solution()
print(sol.searchInsert([1, 3, 5, 6], 5))
print(sol.searchInsert([1, 3, 5, 6], 2))
print(sol.searchInsert([1,3,5,6], 7))
print(sol.searchInsert([1,3,5,6],0))
