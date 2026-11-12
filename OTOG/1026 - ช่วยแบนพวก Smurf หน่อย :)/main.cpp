#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <iomanip>
//#define int long long
#define ts to_string
#define pb push_back
using ll = long long;
using namespace std;

signed main() {
	cin.tie(0) -> sync_with_stdio(0), cout.tie(0);
	int n;
	cin >> n;
	vector<string> a(n);
	for(auto &x : a) cin >> x;
	unordered_map<string, int> mp;
	for(int i = 0; i < n; ++i) {
		string s = a[i];
		string s1 = "";
		for(auto &x : s) s1 += tolower(x);
		auto it = s1.find("_but_");
		if(it != string::npos) {
			++mp[s.substr(0, it)];
		}
		else ++mp[s];
	}
	cout << mp.size();
}
