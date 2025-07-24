class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            string st = to_string(nums[i]);
            for(int j=0; j<st.length(); j++)
            {
                int curr = st[j] - '0';
                ans.push_back(curr);
            }   
        }
        return ans;
    }
};