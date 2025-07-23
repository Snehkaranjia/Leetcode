class Solution {

private:
    int countsub(vector<bool> &removed, string s, string sub)
    {
        stack<pair<int, char>> st;
        int pairs = 0;
        for (int i = 0; i < removed.size(); i++) {
            if (removed[i]) {
                if (s[i] == sub[0]) {
                    st.push({i, s[i]});
                } else if (s[i] == sub[1]) {
                    if (!st.empty() && st.top().second == sub[0]) {
                        removed[st.top().first] = false;
                        removed[i] = false;
                        st.pop();
                        pairs++;
                    }
                } else {
                    st = stack<pair<int, char>>(); 
                }
            }
        }
        return pairs;
    }

public:
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        vector<bool> removed(n, true);
        int ans = 0;
        if (x >= y) {
            ans += countsub(removed, s, "ab") * x;
            ans += countsub(removed, s, "ba") * y;
        } else {
            ans += countsub(removed, s, "ba") * y;
            ans += countsub(removed, s, "ab") * x;
        }
        return ans;
    }
};
