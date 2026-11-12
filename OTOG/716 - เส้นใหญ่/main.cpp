#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <iomanip>
//#define int long long
#define ts to_string
#define pb push_back
using ll = long long;
using namespace std;

int par[100001];
inline int find(int x) { return (par[x] == x ? x : par[x] = find(par[x])); }
inline void unite(int u, int v) { u = find(u), v = find(v); if(u != v) par[u] = v; }

signed main() {
	cin.tie(0)->sync_with_stdio(0), cout.tie(0);
	iota(par, par+100001, 0);
	int n, m, q;
	cin >> n >> m;
	while(m--) {
		int u, v;
		cin >> u >> v;
		unite(u, v);
	}
	cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v;
		u = find(u), v = find(v);
		if(u == v) cout << "true\n";
		else cout << "false\n";
	}
}
