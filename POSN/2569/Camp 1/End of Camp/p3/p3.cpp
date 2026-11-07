#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> adj(26);
vector<int> ans;

void dfs(int u, int p) {
	ans.push_back(u);
	for(int &v : adj[u]) {
		if(v == p) continue;
		dfs(v, u);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0, u, v; i < m && cin >> u >> v; ++i) adj[u].push_back(v), adj[v].push_back(u);
	dfs(1, -1);
	for(int i = 0; i < (int)ans.size(); ++i) cout << ans[i] << (i+1==(int)ans.size() ? "" : "\n");
}
