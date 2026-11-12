#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ts to_string
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define sortv(v) sort((v).begin(), (v).end())
#define sortd(v) sort((v).rbegin(), (v).rend())
#define uniq(v) (v).resize(unique((v).begin(), (v).end()) - (v).begin())
#define rep(i, l, r) for(int i = l; i < r; ++i)
#define per(i, r, l) for(int i = r; i > l; --i)
#define debug(x) cerr << #x << " is " << (x) << '\n';
using ll = long long;
template <class T> using vec = vector<T>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll mod = 1e9+7, inf = 7ll << 58; // mods 998244353, 1e9+7

// binary expo
ll mod_pow(ll b, ll e, ll mode = mod) {
	ll res = 1;
	ll cur = b % mode;
	while(e > 0) {
		if(e&1) res = res * cur % mode;
		cur = cur * cur % mode;
		e >>= 1;
	}
	return res;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vec<int> a(n), pref(n, 0);
	for(int i = 0; i < n && cin >> a[i]; ++i) pref[i] = (i ? pref[i-1] : 0) + a[i];
	unordered_map<int, ll> mp;
	mp.max_load_factor(0.67), mp.reserve(n*2+67);
	ll cnt{0};
	for(int i = k-1; i < n; ++i) {
		++mp[(i-k < 0 ? 0 : pref[i-k])];
		cnt += mp[pref[i]];
	}
	cout << cnt << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int ttt{1};
	//cin >> ttt;
	while(ttt--) solve();
}
