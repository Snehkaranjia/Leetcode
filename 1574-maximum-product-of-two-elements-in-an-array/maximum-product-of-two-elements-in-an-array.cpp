class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for(auto num:nums){
            pq.push(num);
        }
        int n1 = pq.top();
        pq.pop();
        return (n1-1) * (pq.top()-1);
    }
};