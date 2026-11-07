#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> idx(k+1);
    vector<vector<int>> a(n, vector<int> (m));
    int r=-1, c=-1;
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
        cin >> a[i][j];
        if(a[i][j]) idx[a[i][j]] = {i, j};
    }
    bool y = 0;
    string s = "";
    for(int i = 2; i <= k; ++i) {
        auto [pr, pc] = idx[i-1];
        auto [nr, nc] = idx[i];
        int dif = abs(nr - pr), dif1 = abs(pc - nc);
        y |= (dif > 1 || dif1 > 1);
        if(y) break;
        if(nr - pr == 0 && nc - pc == 1) s += "R";
        else if(nr - pr == 0 && nc - pc == -1) s += "L";
        else if(nr - pr == 1 && nc - pc == 0) s += "D";
        else if(nr - pr == -1 && nc - pc == 0) s += "U";
    }
    if(y || (int)s.size() != k-1) return cout << "no", 0;
    cout << "yes\n";
    cout << s;
}
