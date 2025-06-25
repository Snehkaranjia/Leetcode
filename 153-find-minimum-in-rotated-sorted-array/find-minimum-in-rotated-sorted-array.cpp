class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        while(s != e)
        {
            if(nums[n-1] > nums[mid])
                e = mid;
            else
                s = mid + 1;
            mid = s + (e-s)/2;
        }
        return nums[s];
    }
};