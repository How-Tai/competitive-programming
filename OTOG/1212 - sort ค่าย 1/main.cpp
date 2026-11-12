#include <bits/stdc++.h>

using namespace std;

int main() {
    //cin.tie(0)->sync_with_stdio(0);
    int n;
    scanf("%d", &n);
    static int mp[100001];
    for(int i = 0, x; i < n && scanf("%d", &x); ++i) ++mp[x];
    for(int i = 0; i < 100001; ++i) {
        for(int j = 0; j < mp[i]; ++j) printf("%d ", i);
    }
}
