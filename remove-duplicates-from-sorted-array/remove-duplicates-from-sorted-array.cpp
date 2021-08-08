class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums[0];
        int idx = 1;
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > n) {
                count++;
                nums[idx] = nums[i];
                n = nums[i];
                idx++;
            }
        }
        return count;
    }
};