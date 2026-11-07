#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <iomanip>
#define ts to_string
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.rbegin(), v.rend())
#define uniq(v) v.resize(unique(v.begin(), v.end()) - v.begin())
#define rep(i, l, r) for(int i = l; i < r; ++i)
#define per(i, r, l) for(int i = r; i > l; --i)
using ll = long long;
using namespace std;
 
signed main() {
	cin.tie(0)->sync_with_stdio(0), cout.tie(0);
	int n, x;
	cin >> n >> x;
	ll ls = n>>1, rs = n-ls;
	ll cnt = 0;
	vector<ll> a(n);
	unordered_map<ll, ll> mp;
	mp.reserve((ll)(1 << ls)*2), mp.max_load_factor(0.3);
	rep(i, 0, n) cin >> a[i];
	sortv(a);
	rep(mask, 0, (1 << ls)) {
		ll g = 0;
		rep(i, 0, ls) if((mask >> i) & 1) g += a[i];
		++mp[g];
	}
	rep(mask, 0, (1 << rs)) {
		ll g = 0;
		rep(i, 0, rs) if((mask >> i) & 1) g += a[i+ls];
		if(mp.count(x-g)) cnt += mp[x-g];
	}
	cout << cnt;
}
