#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ts to_string
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sortv(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.rbegin(), v.rend())
#define uniq(v) v.resize(unique(v.begin(), v.end()) - v.begin())
#define rep(i, l, r) for(int i = l; i < r; ++i)
#define per(i, r, l) for(int i = r; i > l; --i)
#define debug(x) cerr << #x << " is " << (x) << '\n';
using ll = long long;
using ull = unsigned long long;
template <class T> using vec = vector<T>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll mod = 998244353, inf = 7ll << 58;

// binary expo
ll mod_pow(ll b, ll e, ll mode = mod) {
    ll res{1ll}, cur = b%mode;
    while(e > 0) {
        if(e & 1) res = res * cur % mode;
        cur = cur * cur % mode;
        e >>= 1;
    }
    return res;
}

void solve() {
    int q;
    cin >> q;
    vec<ll> dp(2001, 0);
    dp[0] = 1;
    for(int i = 1; i <= 2000; ++i) {
        for(int j = 2000; j >= i; --j) {
            dp[j] += dp[j-i];
            dp[j] %= 1'000'003;
        }
    }
    while(q--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}

signed main() {
	cin.tie(0)->sync_with_stdio(0), cout.tie(0);
	int ttt{1};
	//cin >> ttt;
	while(ttt--) solve();
}

