#pragma GCC optimize("O5, unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define int long long
#define ts to_string
#define pb push_back
#define ow ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

signed main(){
	ow
	int s, m;
    cin >> s >> m;
    bool found = 0;
    int xa = -1, ya = -1;
    for(int x = 1; x < s; x++){
        int y = s - x;
        if(x * y == m){
            xa = min(x, y);
            ya = max(x, y);
            found = 1;
            break;
        }
    }
    if(found) cout << xa << " " << ya;
    else cout << "Goodbye T-T";
}
