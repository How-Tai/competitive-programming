#include <bits/stdc++.h>

int main() {
    int n, k;
    std::scanf("%d%d", &n, &k);
    std::vector<int> a(n);
    for(auto &e : a) std::scanf("%d", &e);
    static std::bitset<1000001> bs;
    bs.set();
    bs[0] = bs[1] = 0;
    for(int i = 2; i*i <= 1000000; ++i)
        for(int j = i+i; bs[i] && j <= 1000000; j += i) bs[j] = 0;

    std::vector<int> v;
    v.reserve(n);
    for(int i = 0; i < n; ++i) if(bs[a[i]]) v.push_back(i);

    int ans{n};

    for(int i = 0; i-1 < (int)v.size() - k; ++i) ans = std::min(ans, v[i+k-1] - v[i]+1);
    std::printf("%d", ans);

}
