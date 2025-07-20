class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<pair<int,char>>v;
        int n=nums.size();
        for(auto i:nums){
            v.push_back({i-k,'x'});
            v.push_back({i+k,'y'});
        }
        sort(v.begin(),v.end());
        int ans=0,cnt=0;
        for(auto i:v){
            if(i.second=='x'){
                cnt++;
            }
            if(i.second=='y')cnt--;
            ans=max(ans,cnt);
        }
        return ans;
    }
};