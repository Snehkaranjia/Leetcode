class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;
        int mid = s + (e - s) / 2;
        while (s != e) {
            if (nums[mid + 1] > nums[mid])
                s = mid + 1;
            else
                e = mid;
            mid = s + (e - s) / 2;
        }
        return mid;
    }
};