#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <iomanip>
#define ts to_string
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
using ll = long long;
using namespace std;

signed main() {
	cin.tie(0) -> sync_with_stdio(0), cout.tie(0);
	int n;
	cin >> n;
	int se = (n+1)*n/2;
	ll cnt = 0;
	if(se&1) return cout << 0, 0;
	se /= 2;
	int sz = n/2;
	unordered_map<ll, ll> mp;
	mp.max_load_factor(0.25);
	mp.reserve(n);
	for(int mask = 0; mask < (1 << sz); ++mask) {
		ll g = 0;
		for(int i = 0; i < sz; ++i) g += ((mask >> i) & 1 ? i+1 : 0);
		++mp[g];
	}
	int sz1 = n-sz;
	for(int mask = 0; mask < (1 << sz1); ++mask) {
		ll g = 0;
		for(int i = 0; i < sz1; ++i) g += ((mask >> i) & 1 ? sz + i+1 : 0);
		cnt += mp[se-g];
	}
	cout << cnt/2;
}
