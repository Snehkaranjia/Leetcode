class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        if (nums.size() == 1)
            return 1;
        int j = 1;
        while (j < nums.size()) {
            if (nums[i] != nums[j]) {
                nums[i + 1] = nums[j];
                i++;
            }
            j++;
        }
        nums.erase(nums.begin() + i + 1, nums.end());
        return nums.size();
    }
};