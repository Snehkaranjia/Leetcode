class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        priority_queue<int> mhp;
        priority_queue<int> mht;

        for(auto &p : players)
            mhp.push(p);
        
        for(auto &t : trainers)
            mht.push(t);

        int ans = 0;
        while(!mhp.empty() && !mht.empty())
        {
            if(mhp.top() <= mht.top())
            {
                ans++;
                mhp.pop();
                mht.pop();
            }
            else
            {
                mhp.pop();
            }
        }
        return ans;
    }
};