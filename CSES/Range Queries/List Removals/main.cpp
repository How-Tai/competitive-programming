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
vector<long long> tree;
 
void build(int v, int l, int r) {
	if(l == r) { tree[v] = 1; return; }
	
	int mid = l + (r - l) / 2;
	build(2*v, l, mid);
	build(2*v+1, mid+1, r);
	
	tree[v] = tree[2*v] + tree[2*v+1];
}
 
void update(int v, int l, int r, int pos, long long x) {
	if(l == r) { tree[v] -= 1; return; }
	
	int mid = l + (r - l) / 2;
	
	if(pos <= mid) update(2*v, l, mid, pos, x);
	else update(2*v+1, mid+1, r, pos, x);
	
	tree[v] = tree[2*v] + tree[2*v+1];
}
 
void build() { build(1, 1, n); }
void update(int pos, long long val) { update(1, 1, n, pos, val); }
 
void traverse(int v, int &ans, int k, int l, int r) {
	if(l == r) { ans = l; return; }
	
	int mid = l + (r - l) / 2;
	if(k <= tree[2*v]) traverse(2*v, ans, k, l, mid);
	else { traverse(2*v+1, ans, k - tree[2*v], mid+1, r); }
}
 
void solve() {
	cin >> n;
	a.resize(n+1), tree.resize(4*n+20);
	for(int i = 1; i <= n; ++i) cin >> a[i];
	build();
	for(int i = 0; i < n; ++i) {
		int ans;
		int k;
		cin >> k;
		traverse(1, ans, k, 1, n);
		update(ans, -1);
		cout << a[ans] << ' ';
	}
}
 
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int ttt{1};
	//cin >> ttt;
	while(ttt--) solve();
}
