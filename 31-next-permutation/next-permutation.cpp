class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int bp = -1;

        //find bp "/\"
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                bp = i;
                break;
            }
        }

        //if decreasing
        if(bp == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        //swap bp with just bigger than that
        for(int i=n-1; i>bp; i--)
        {
            if(nums[i] > nums[bp])
            {
                swap(nums[i], nums[bp]);
                break;
            }
        }

        //reverse after bp array
        reverse(nums.begin()+bp+1, nums.end());
    }
};