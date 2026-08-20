class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1 = {nums[0]}, arr2 = {nums[1]};
        for(int i=2; i<n; i++)
            arr1[arr1.size()-1] > arr2[arr2.size()-1] ? arr1.push_back(nums[i]) : arr2.push_back(nums[i]);
        for(auto it : arr2)
            arr1.push_back(it);
        return arr1;
    }
};