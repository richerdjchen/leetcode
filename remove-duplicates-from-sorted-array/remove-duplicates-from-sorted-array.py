class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if (len(nums) <= 1):
            return len(nums)
        prev = nums[0]
        idx = 1
        count = 1
        for i in range(1,len(nums)):
            if (nums[i] <= prev):
                continue
            prev = nums[i]
            tmp = nums[idx]
            nums[idx] = nums[i]
            nums[i] = tmp
            idx += 1
            count += 1
        return count
            