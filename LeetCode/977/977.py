class Solution:
	def sortedSquares(self, nums: list[int]) -> list[int]:
		l, r = (0, len(nums)-1)
		ans = []
		while l <= r:
			if nums[l]**2 < nums[r]**2:
				ans.append(nums[r]**2)
				r -= 1
			else:
				ans.append(nums[l]**2)
				l += 1
		ans.reverse()
		return ans
			
_ = Solution()
print(_.sortedSquares([-4,-1,0,3,10]))