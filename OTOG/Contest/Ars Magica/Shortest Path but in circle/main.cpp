#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<long long> a(n+n), pref(n+n);
    for(int i = 0; i < n; ++i) cin >> a[i], a[i+n] = a[i];
    pref[0] = a[0];
    for(int i = 1; i < n+n; ++i) pref[i] = pref[i-1] + a[i];
    long long total = pref[n-1];
    while(q--) {
        int s, t;
        cin >> s >> t;
        if(s == t) { cout << "0 "; continue; }
        if(t < s) t += n;
        long long l = pref[t-2] - (s >= 2 ? pref[s-2] : 0);
        long long r = total - l + a[s-1] - a[(t-1)%n];
        cout << min(l, r) << ' ';
    }
}
