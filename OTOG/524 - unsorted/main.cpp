#include <bits/stdc++.h>
//#define int long long
#define ts to_string
#define pb push_back
using ll = long long;
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    random_shuffle(a.begin(), a.end());
    for(auto &x : a) cout << x << ' ';
}
