class Solution {
public:
    string smallestPalindrome(string s) {
        string left = "", middle = "", right = "", ans="";
        
        map<char, pair<int, bool>> mp;

        for (auto it : s) {
            mp[it].first++;
            mp[it].second = false;
        }

        for (auto &it : mp) {
            while (it.second.first > 1) {
                left += it.first;
                it.second.first -= 2;
                it.second.second = true;
            }
        }
        ans+=left;
        
        for (auto &it : mp) {
            if (it.second.first == 1) {
                middle += it.first;
                it.second.first--;
                break;
            }
        }
        ans+=middle;
        
        reverse(left.begin(), left.end());

        ans+=left;

        return ans;
    }
};