#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    long long sum = 0;
    for(int i = 0; i < n; ++i) sum += max(0, a[i]);
    cout << sum;
}
