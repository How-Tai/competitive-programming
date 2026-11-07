#include "bits/stdc++.h"
#include <cassert>
using namespace std;
#define ts to_string
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sortv(v) sort((v).begin(), (v).end())
#define sortd(v) sort((v).rbegin(), (v).rend())
#define uniq(v) (v).resize(unique((v).begin(), (v).end()) - (v).begin())
#define chmax(x, y) (x) = std::max((ll)(x), (ll)(y))
#define chmin(x, y) (x) = std::min((ll)(x), (ll)(y))
#define rep(i, l, r) for(int i = l; i < r; ++i)
#define per(i, r, l) for(int i = r; i > l; --i)
#define readv(v) for(auto &e : (v)) cin >> e;
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
 
int n, q;
vector<int> a;
vector<long long> tree, lazy;
 
void build(int v, int l, int r) {
	if(l == r) {
		tree[v] = a[l];
		return;
	}
	int mid = l + (r - l) / 2;
	build(2*v, l, mid);
	build(2*v+1, mid+1, r);
	tree[v] = max(tree[2*v], tree[2*v+1]);
}
 
void apply(int v, int l, int r, long long val) {
	tree[v] += val;
	lazy[v] += val;
}
 
void push(int v, int l, int r) {
	if(l == r || lazy[v] == 0) return;
	int mid = l + (r - l) / 2;
	apply(2*v, l, mid, lazy[v]);
	apply(2*v+1, mid+1, r, lazy[v]);
	lazy[v] = 0;
}
 
void update(int v, int l, int r, int ql, int qr, long long val) {
	if(r < ql || qr < l) return;
	
	if(ql <= l && r <= qr) {
		apply(v, l, r, val);
		return;
	}
	
	push(v, l, r);
	
	int mid = l + (r - l) / 2;
	update(2*v, l, mid, ql, qr, val);
	update(2*v+1, mid+1, r, ql, qr, val);
	tree[v] = max(tree[2*v], tree[2*v+1]);
}
 
long long query(int v, int l, int r, int ql, int qr) {
	if(l > qr || r < ql) return -inf;
	if(ql <= l && r <= qr) return tree[v];
	
	push(v, l, r);
	
	int mid = l + (r - l) / 2;
	return max(query(2*v, l, mid, ql, qr), query(2*v+1, mid+1, r, ql, qr));
}
 
void build(int l, int r) { build(1, l, r); }
void update(int l, int r, long long val) { update(1, 1, n, l, r, val); }
long long query(int ql, int qr) { return query(1, 1, n, ql, qr); }
 
void traverse(int &idx, int &need, int l, int r, int v) {
	if(l == r) { idx = l; return; }
	int mid = l + (r - l) / 2;
	push(v, l, r);
	if(tree[2*v] >= need) traverse(idx, need, l, mid, 2*v);
	else if(tree[2*v+1] >= need) traverse(idx, need, mid+1, r, 2*v+1);
	else idx = -1;
}
 
void solve() {
	cin >> n >> q;
	a.resize(n+1), tree.resize(4*n + 20), lazy.assign(4*n + 20, 0);
	for(int i = 1; i <= n; ++i) cin >> a[i];
	build(1, n);
	while(q--) {
		int ned;
		cin >> ned;
		int check = query(1, n);
		if(check < ned) { cout << "0 "; continue; }
		int idx = 0;
		traverse(idx, ned, 1, n, 1);
		cout << idx << ' ';
		update(idx, idx, -ned);
	}
}
 
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int ttt{1};
	//cin >> ttt;
	while(ttt--) solve();
}
