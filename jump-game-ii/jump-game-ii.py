class Solution:
    def jump(self, nums: List[int]) -> int:
        dp = [len(nums) for _ in range(len(nums))]
        dp[0] = 0
        for i in range(len(nums)):
            jumps = 1
            while(i + jumps < len(nums) and jumps <= nums[i]):
                dp[i + jumps] = min(dp[i] + 1, dp[i+jumps])
                jumps += 1
        return dp[len(nums)-1]