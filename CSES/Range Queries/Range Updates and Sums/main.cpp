#include "bits/stdc++.h"
using namespace std;
 
const int MAXN = 200005;
int n, q;
vector<int> a;
vector<long long> tree, lazy;
bitset<4*MAXN> has_assign, has_add;
 
void apply(int v, int l, int r, int type, long long x) {
	if(type == 1) {
		tree[v] += (r - l + 1) * x;
		lazy[v] += x;
		if(!has_assign[v]) has_add[v] = 1;
	}
	else if(type == 2) {
		tree[v] = (r - l + 1) * x;
		lazy[v] = x;
		has_assign[v] = 1;
	}
}
 
void push(int v, int l, int r) {
	if(l == r || (!has_assign[v] && !has_add[v])) return;
	int mid = l + (r - l) / 2;
	int type = 1;
	if(has_assign[v]) type = 2;
	apply(2*v, l, mid, type, lazy[v]);
	apply(2*v+1, mid+1, r, type,lazy[v]);
	lazy[v] = 0;
	has_assign[v] = 0;
	has_add[v] = 0;
}
 
void build(int v = 1, int l = 1, int r = n) {
	if(l == r) { tree[v] = a[l]; return; }
	int mid = l + (r - l) / 2;
	build(2*v, l, mid);
	build(2*v+1, mid+1, r);
	tree[v] = tree[2*v] + tree[2*v+1];
}
 
void update(int v, int l, int r, int ql, int qr, int type, long long x) {
	if(l > qr || r < ql) return; 
	if(ql <= l && r <= qr) { apply(v, l, r, type, x); return; }
	push(v, l, r);
	int mid = l + (r- l) / 2;
	update(2*v, l, mid, ql, qr, type, x);
	update(2*v+1, mid+1, r, ql, qr, type, x);
	tree[v] = tree[2*v] + tree[2*v+1];
}
 
long long query(int v, int l, int r, int ql, int qr) {
	if(r < ql || l > qr) return 0ll;
	if(ql <= l && r <= qr) return tree[v];
	
	push(v, l, r);
	int mid = l + (r - l) / 2;
	return query(2*v, l, mid, ql, qr) + query(2*v+1, mid+1, r, ql, qr);
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q;
	a.resize(n+1), tree.assign(4*n+20, 0), lazy.assign(4*n+20, 0);
	for(int i = 1; i <= n; ++i) cin >> a[i];
	build();
	while(q--) {
		int type;
		cin >> type;
		if(type == 1 || type == 2) {
			int l, r;
			long long x;
			cin >> l >> r >> x;
			update(1, 1, n, l, r, type, x);
		}
		if(type == 3) {
			int l, r;
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << '\n';
		}
	}
}
