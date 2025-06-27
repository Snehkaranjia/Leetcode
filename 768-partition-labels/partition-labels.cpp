class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        int start=0,end=0,cnt=0;
        vector<int> ans;
        map<char, int> last_occ;
        for(int i=0; i<n; i++)
            last_occ[s[i]] = i;
            
        while(start < n)
        {
            end = max(end, last_occ[s[start]]);
            if(start == end)
            {
                ans.push_back(cnt+1);
                start++;
                end++;
                cnt=0;
            }
            else
            {
                cnt++;
                start++;
            }
        }
        return ans;
    }
};