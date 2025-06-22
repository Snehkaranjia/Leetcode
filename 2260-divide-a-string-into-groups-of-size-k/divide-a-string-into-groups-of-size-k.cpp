class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string> ans;
        string temp = "";
        int count = k;
        for (int i = 0; i < n; i++) {
            temp += s[i];
            count--;
            if (count == 0) {
                ans.push_back(temp);
                temp = "";
                count = k;
            }
        }
        if (temp != "") {
            while (count != 0) {
                temp += fill;
                count--;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};