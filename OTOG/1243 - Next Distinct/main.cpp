#include "bits/stdc++.h"
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int ttt{1};
	cin >> ttt;
	while(ttt--) {
		int n;
		cin >> n;
		
		if(n <= 9) {
			cout << n+1 << '\n';
			continue;
		}
		
		int tmp = n;
		int len = 0;
		while(tmp) tmp /= 10, ++len;
		tmp = n;
		
		bool freq[10];
		memset(freq, 0, 10);
		string s = "0" + to_string(n);
		
		function<int(int)> mex = [&](int x) -> int {
			for(int i = x+1; i <= 9; ++i) if(!freq[i]) return i;
			return 10;
		};
		
		bool eo = 0;
		
		for(int i = 0; i <= len; ++i) {
			if(i == 0 && s[i] == '0') continue;
			eo = s.substr(0, i) > ("0" + to_string(n)).substr(0, i);
			if(eo) s[i] = mex(-1) + '0';
			else if(freq[s[i] - '0'] || i == len) { s[i] = mex(s[i] - '0') + '0'; }
			else {}
			if(s[i] == '0' + 10) {
				while(s[i] >= '9') s[i] = '0', --i;
				++s[i];
				goto nxt;
			}
			freq[s[i] - '0'] ^= 1;
			continue;
			
			nxt:;
			i = -1, eo = 0;
			memset(freq, 0, 10);
		}
		
		cout << stoi(s) << '\n';
	}
}
