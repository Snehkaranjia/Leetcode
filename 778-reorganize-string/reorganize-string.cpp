class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> freq_map;
        for (char c : s) {
            freq_map[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto const& [ch, freq] : freq_map) {
            pq.push({freq, ch});
        }

        string ans = "";
        while (pq.size() >= 2) {
            auto [f1, c1] = pq.top();
            pq.pop();
            auto [f2, c2] = pq.top();
            pq.pop();

            ans += c1;
            ans += c2;

            if (--f1 > 0)
                pq.push({f1, c1});
            if (--f2 > 0)
                pq.push({f2, c2});
        }

        if (!pq.empty()) {
            auto [f, c] = pq.top();
            if (f > 1)
                return "";
            ans += c;
        }
        return ans;
    }
};