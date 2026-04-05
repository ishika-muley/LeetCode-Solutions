1class Solution:
2    def hasTrailingZeros(self, nums: List[int]) -> bool:
3        count_even = 0
4        
5        for num in nums:
6            if num % 2 == 0:
7                count_even += 1
8        
9        return count_even >= 2