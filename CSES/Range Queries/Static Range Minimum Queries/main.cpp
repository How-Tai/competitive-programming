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
	vector<ll> a(n);
	int LOG = __lg(n)+1;
	rep(i, 0, n) cin >> a[i];
	vector<vector<ll>> st(LOG, vector<ll> (n)); // Sparse Table
	rep(i, 0, n) st[0][i] = a[i];
	rep(i, 1, LOG) for(int j = 0; j+(1<<i) <= n; ++j) st[i][j] = min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
	while(q--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		int logg = __lg(v-u+1);
		cout << min(st[logg][u], st[logg][v-(1<<logg)+1]) << '\n';
	}
}
