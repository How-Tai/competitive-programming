#include <bits/stdc++.h>
#define ts to_string
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define uniq(v) v.resize(unique(v.begin(), v.end()) - v.begin())
using ll = long long;
using namespace std;

int par[100001];
inline int find(int x) { return (x == par[x] ? x : par[x] = find(par[x])); }
inline bool unite(int u, int v) { u = find(u), v = find(v); if(u != v) { par[u] = v; return 1; } return 0; }

signed main(){
    cin.tie(0)->sync_with_stdio(0), cout.tie(0);
    iota(par, par+100001, 0);
    int n, m, k;
    ll cost = 0;
    cin >> n >> m >> k;
    vector<tuple<int, int, int>> a(m);
    multiset<ll> s;
    for(auto &[w, u, v] : a) cin >> u >> v >> w;
    sortv(a);
    for(auto &[w, u, v] : a) if(unite(u, v)) { s.insert(w); }
    while(k--) {
       auto it = prev(s.end());
       ll x = *it / 2;
       s.erase(it), s.insert(x);
    }
    for(auto &x : s) cost += x;
    cout << cost;
}
