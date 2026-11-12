#include <bits/stdc++.h>
#define ts to_string
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.rbegin(), v.rend())
#define uniq(v) v.resize(unique(v.begin(), v.end()) - v.begin())
#define rep(i, l, r) for(int i = l; i < r; ++i)
#define per(i, r, l) for(int i = r; i >= l; --i)
using ll = long long;
using namespace std;

int par[250000];
inline int find(int x) { return(par[x] == x ? x : par[x] = find(par[x])); }
inline bool unite(int u, int v) { u = find(u), v = find(v); if(u == v) return 0; par[u] = v; return 1; }

signed main(){
    cin.tie(0)->sync_with_stdio(0), cout.tie(0);
    iota(par, par+250000, 0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<tuple<int, int, int>> a;
    a.reserve(n*m);
    int h;
    rep(i, 0, n) rep(j, 0, m) cin >> h, a.pb({h, i, j});
    sortv(a);
    vector<int> v((n*m+1)/2, -1);
    vector<int8_t> flooded(n*m, 0);
    int pud = 0;
    int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, -1, 1};
    for(int i = 0; i < (int)a.size();) {
        int j = i;
        while(j < (int)a.size() && get<0>(a[i]) == get<0>(a[j])) {
            int r = get<1>(a[j]), c = get<2>(a[j]);
            int pos = r*m+c;
            flooded[pos] = 1;
            ++pud;
            for(int d = 0; d < 4; ++d) {
                int nr = r + dr[d], nc = c + dc[d];
                if(nr >= n || nr < 0 || nc >= m || nc < 0) continue;
                if(!flooded[nr*m+nc]) continue;
                if(unite(pos, nr*m+nc)) --pud;
            }
            ++j;
        }
        if(!(v[pud]+1)) v[pud] = get<0>(a[i])+1;
        i = j;
    }
    while(q--) {
        int k;
        cin >> k;
        cout << v[k] << '\n';
    }
}
