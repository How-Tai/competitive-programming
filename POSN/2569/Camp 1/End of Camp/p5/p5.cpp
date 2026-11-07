#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<long long> t(n);
    long long mult = 1e6;
    for(long long i = 0, x; i < n && cin >> x; ++i) t[i] = ((x+k-1) / k) * mult + i;
    sort(t.begin(), t.end());
    for(int i = 0; i < n; ++i) cout << t[i] % mult + 1 << (i+1 == n ? "" : " ");
}
