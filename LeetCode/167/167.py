class Solution:
  def twoSum(self, numbers: list[int], target: int) -> list[int]:
    i = 0; j = len(numbers)-1
    while i < j:
      sum = numbers[i] + numbers[j]
      if sum == target:
        return [i+1, j+1]
      elif sum < target:
        i += 1
      else:
        j -= 1

_ = Solution()
print(_.twoSum([2,7,11,15], 9))
print(_.twoSum([2,3,4], 6))
print(_.twoSum([-1, 0], -1))

        