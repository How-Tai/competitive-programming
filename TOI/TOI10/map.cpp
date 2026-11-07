#include "bits/stdc++.h"
using namespace std;

int m, n, cnt;
vector<vector<pair<char, int>>> adj(40000);
bitset<40000> vis;
int ups, lefts;
int posx, posy;
vector<vector<int>> ans(200, vector<int> (200, -1));

void dfs1(int u, int up, int left) {
	if(vis[u]) return;
	vis[u] = 1;
	ups = max(ups, up);
	lefts = max(lefts, left);
	vector<pair<char, int>> &vec = adj[u];
	
	for(int i = 0; i < (int)vec.size(); ++i) {
		char d;
		int y;
		tie(d, y) = vec[i];
		dfs1(y, up + (d == 'U') - (d == 'D'), left + (d == 'L') - (d == 'R'));
	}
}

void dfs2(int u, int up, int left) {
	if(vis[u]) return;
	vector<pair<char, int>> &vec = adj[u];
	ans[posx-up][posy-left] = u;
	vis[u] = 1;
	
	for(int i = 0; i < (int)vec.size(); ++i) {
		char d;
		int y;
		tie(d, y) = vec[i];
		dfs2(y, up + (d == 'U') - (d == 'D'), left + (d == 'L') - (d == 'R'));
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> m >> n;
	cnt = m * n - 1;
	ups = lefts = 0;
	
	for(int i = 0; i < cnt; ++i) {
		int x, y;
		char d;
		cin >> x >> d >> y;
		adj[y].push_back(make_pair(d, x));
		adj[x].push_back(make_pair((d == 'U' ? 'D' : 'R'), y));
	}
	
	vis = 0;
	
	dfs1(0, 0, 0);
	
	vis = 0;
	
	posy = lefts, posx = ups;
	ans[posx][posy] = 0;
	dfs2(0, 0, 0);
	
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << ans[i][j] << " \n"[j+1==n];
		}
	}
}
