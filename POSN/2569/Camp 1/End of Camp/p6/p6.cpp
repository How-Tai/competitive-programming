#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    long long n, m, r;
    cin >> n >> m >> r;
    vector<long long> a(m);
    for(int i = 0; i < m; ++i) cin >> a[i];
    vector<long long> x(n), y(n);
    for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];
    long long tmp = r * r;

    int cnt1, cnt2;
    cnt1 = cnt2 = 0;

    for(int i = 0; i < n; ++i) cnt1 += (x[i] - a[0]) * (x[i] - a[0]) + (y[i] * y[i]) <= tmp;

    sort(a.begin(), a.end());

    for(int i = 0; i < n; ++i) {
        auto it = lower_bound(a.begin(), a.end(), x[i]);

        int8_t yy = 0;
        if(it != a.end()) yy |= (x[i] - *it) * (x[i] - *it) + (y[i] * y[i]) <= tmp;
        if(it != a.begin()) --it, yy |= (x[i] - *it) * (x[i] - *it) + (y[i] * y[i]) <= tmp, ++it;

        cnt2 += yy;
    }
    cout << cnt2 << '\n' << cnt1;
}
