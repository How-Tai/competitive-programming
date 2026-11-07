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
	int n, q;
	cin >> n >> q;
	vector<ll> a(n), pref(n, 0);
	rep(i, 0, n) cin >> a[i];
	pref[0] = a[0];
	rep(i, 1, n) pref[i] = pref[i-1]+a[i];
	while(q--) {
		int u, v;
		cin >> u >> v;
		cout << pref[v-1] - (u-1 ? pref[u-2] : 0) << '\n';
	}
}
