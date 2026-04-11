class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        positions = defaultdict(list)

        for i, num in enumerate(nums):
            positions[num].append(i)

        result = math.inf
        for position in positions.values():
            if len(position) < 3:
                continue
            
            for idx in range(2, len(position)):
                i, j, k = position[idx - 2], position[idx - 1], position[idx]
                dist = abs(i - j) + abs(j - k) + abs(k - i)
                result = min(result, dist)

        return result if result != math.inf else -1