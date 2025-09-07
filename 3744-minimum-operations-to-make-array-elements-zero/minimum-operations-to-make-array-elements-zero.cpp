#define ll long long
class Solution {
public:
    long long minOperations(vector<vector<int>>& qry) {
        vector<pair<ll, ll>> interval;
        ll val = 1;
        for (int i = 0; i < 17; i++) {
            ll L = val;
            ll R = val * 4 - 1;
            interval.push_back({L, R});
            val *= 4;
        }

        int N = qry.size();
        long long sum = 0LL;

        for (int i = 0; i < N; i++) {
            ll p = qry[i][0], q = qry[i][1], temp = 0LL;
            for (int j = 0; j < 17; j++) {
                ll L = interval[j].first;
                ll R = interval[j].second;

                if (q < L || p > R) {
                    continue;
                }

                if (p < L && q <= R) { // p  | q |
                    temp += (q - L + 1) * (j + 1);
                } else if (L <= p && q <= R) { // | p q |
                    temp += (q - p + 1) * (j + 1);
                } else if (L <= p && R < q) { // | p | q
                    temp += (R - p + 1) * (j + 1);
                } else if (p < L && R < q) { // p |   | q
                    temp += (R - L + 1) * (j + 1);
                }
            }
            sum += (temp + 1) / 2;
        }

        return sum;
    }
};