#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1000000007LL;

ll ipow(ll base, int exp, ll limit) {
    ll res = 1;
    for (int i = 0; i < exp; ++i) {
        if (base == 0)
            return 0;
        if (res > limit / base)
            return limit + 1;
        res *= base;
    }
    return res;
}

class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int> powvec;
        for (ll i = 1;; ++i) {
            ll p = ipow(i, x, n);
            if (p > n)
                break;
            powvec.push_back((int)p);
        }

        vector<ll> dp(n + 1, 0);
        dp[0] = 1;
        for (int val : powvec) {
            for (int s = n; s >= val; --s) {
                dp[s] = (dp[s] + dp[s - val]) % MOD;
            }
        }
        return (int)dp[n];
    }
};
