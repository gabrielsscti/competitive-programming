# The isBadVersion API is already defined for you.
def isBadVersion(version: int) -> bool:
  if version >= 2:
    return True
  return False

class Solution:
  def firstBadVersion(self, n: int) -> int:
    start = 0; end = n+1
    if n == 1:
      return 1
    while(start < end):
      mid = (start+end)//2
      print(start, mid, end)
      ant = isBadVersion(mid-1)
      act = isBadVersion(mid)
      if act and not(ant):
        return mid
      elif act and ant:
        end = mid
      else:
        start = mid+1

_ = Solution()
print(_.firstBadVersion(2))
