#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    map<int, vector<int>> mp;
    for(int i = 0, x; i < n && cin >> x; ++i) mp[x].push_back(i+1);
    while(q--) {
        int x;
        cin >> x;
        if(mp[x].empty()) cout << -1;
        else for(int i = 0; i < (int)mp[x].size(); ++i) cout << mp[x][i] << (i+1==(int)mp[x].size() ? "" : " ");
        if(q) cout << "\n";
    }
}
