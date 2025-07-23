class Solution {
private:
    int countx(vector<bool> &removed, string s)
    {
        stack<pair<int, char>> st;
        int abpair = 0;
        for (int i = 0; i < removed.size(); i++) {
            if (removed[i]) {
                if (s[i] == 'a') {
                    st.push({i, s[i]});
                } else if (s[i] == 'b') {
                    if (!st.empty() && st.top().second == 'a') {
                        removed[st.top().first] = false;
                        removed[i] = false;
                        st.pop();
                        abpair++;
                    }
                } else {
                    st = stack<pair<int, char>>(); 
                }
            }
        }
        return abpair;
    }

    int county(vector<bool> &removed, string s)
    {
        stack<pair<int, char>> st;
        int bapair = 0;
        for (int i = 0; i < removed.size(); i++) {
            if (removed[i]) {
                if (s[i] == 'b') {
                    st.push({i, s[i]});
                } else if (s[i] == 'a') {
                    if (!st.empty() && st.top().second == 'b') {
                        removed[st.top().first] = false;
                        removed[i] = false;
                        st.pop();
                        bapair++;
                    }
                } else {
                    st = stack<pair<int, char>>(); 
                }
            }
        }
        return bapair;
    }

public:
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        vector<bool> removed(n, true);
        int ans = 0;
        if (x >= y) {
            ans += countx(removed, s) * x;
            ans += county(removed, s) * y;
        } else {
            ans += county(removed, s) * y;
            ans += countx(removed, s) * x;
        }
        return ans;
    }
};
