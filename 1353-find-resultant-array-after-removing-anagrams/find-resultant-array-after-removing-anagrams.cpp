class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        
        vector<string> temp = words;

        for(auto &str : words)
            sort(str.begin(), str.end());

        vector<string> ans;
        ans.push_back(temp[0]);
        for(int i=1; i<words.size(); i++)
        {
            if(words[i] != words[i-1])
            {
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};