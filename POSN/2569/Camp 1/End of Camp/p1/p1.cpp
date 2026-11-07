#include "bits/stdc++.h"

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int r, c;
	cin >> r >> c;
	vector<string> a(r);
	for(int i = 0; i < r; ++i) cin >> a[i];
	vector<int> x, y;
	for(int i = 0; i < r; ++i) for(int j = 0; j < c; ++j) if(a[i][j] == '1') x.push_back(i), y.push_back(j);
	
	int mn = r*c+1, mx = 0;
	for(int i = 0; i < (int)x.size(); ++i) for(int j = i+1; j < (int)y.size(); ++j) mn = min(mn, abs(x[j] - x[i]) + abs(y[j] - y[i])), mx = max(mx, abs(x[j] - x[i]) + abs(y[j] - y[i]));
	
	cout << mn << ' ' << mx << '\n' << (int)x.size();
}
