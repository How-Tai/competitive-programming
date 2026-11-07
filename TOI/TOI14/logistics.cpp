/*
TASK: logistics.cpp
LANG: C++
AUTHOR: How
CENTER: KNW
*/

#include <bits/stdc++.h>

using namespace std;

int s, d, f;
vector<int> a(101);
vector<vector<pair<int, int>>> adj(101);
long long mn = (7ll << 58);
long long dist[101][101][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(dist, 0x3f, sizeof(dist));
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    cin >> s >> d >> f;
    --s, --d;
    if(s == d) return cout << 0, 0;
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        adj[a].push_back({w, b}), adj[b].push_back({w, a});
    }

    priority_queue<tuple<long long, int, int, bool>, vector<tuple<long long, int, int, bool>>, greater<tuple<long long, int, int, bool>>> pq; // cost, fuel, u, used
    dist[s][0][0] = 0;
    pq.emplace(0ll, 0, s, 0);

    while(!pq.empty()) {
        auto info = pq.top();
        long long cst;
        int fuel, u, used;
        tie(cst, fuel, u, used) = info;
        pq.pop();
        if(cst > dist[u][fuel][used]) continue;
        for(int i = fuel; i <= f; ++i) for(int j = 0; j <= used; ++j) if(dist[u][i][j] < cst) goto nxt;
        dist[u][fuel][used] = cst;
        if(!used && cst < dist[u][f][1]) { dist[u][f][1] = cst; pq.emplace(cst, f, u, 1); }
        for(auto &[w, v] : adj[u]) if(fuel >= w && cst < dist[v][fuel-w][used]) { dist[v][fuel-w][used] = cst; pq.emplace(cst, fuel - w, v, used); }
        if(fuel < f && cst + a[u] < dist[u][fuel+1][used]) { dist[u][fuel+1][used] = cst + a[u]; pq.emplace(cst+a[u], fuel+1, u, used); }
        nxt:;
    }

    cout << min(dist[d][f][0], dist[d][f][1]);
}
