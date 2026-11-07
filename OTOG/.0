#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ts to_string
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sortv(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.rbegin(), v.rend())
#define uniq(v) v.resize(unique(v.begin(), v.end()) - v.begin())
#define rep(i, l, r) for(int i = l; i < r; ++i)
#define per(i, r, l) for(int i = r; i > l; --i)
#define debug(x) cerr << #x << " is " << (x) << '\n';
using ll = long long;
using ull = unsigned long long;
template <class T> using vec = vector<T>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll mod = 998244353, inf = 7ll << 58;

// binary expo
ll mod_pow(ll b, ll e, ll mode = mod) {
    ll res{1ll}, cur = b%mode;
    while(e > 0) {
        if(e & 1) res = res * cur % mode;
        cur = cur * cur % mode;
        e >>= 1;
    }
    return res;
}

ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

void solve() {
    int n, qq;
    cin >> n >> qq;
    vec<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vec<ll> q(qq);
    for(int i = 0; i < qq; ++i) cin >> q[i];
    sortv(a);
    ll mx = *max_element(q.begin(), q.end());
    int idx = 0;
    while(idx < n && a[idx] <= mx) ++idx;
    a.resize(idx);
    vec<vec<int>> divs(mx+1);
    for(int i = 1; i <= mx; ++i) {
        for(int j = i; j <= mx; j += i) {
            divs[j].pb(i);
        }
    }
    vec<int> freq(mx+1, 0);
    for(auto &x : a) ++freq[x];
    vec<int8_t> ways(mx+1, 0);
    for(int i = 1; i <= mx; ++i) {
        if(!freq[i]) continue;
        for(int j = i; (ll)i * j <= (ll)mx; ++j) {
            if(!freq[j]) continue;
            ll add{0};
            if(i == j) add = 1ll * freq[i] * (freq[j]-1)/2;
            else add = 1ll * freq[i] * freq[j];
            ways[i*j] = min(ways[i*j]+add, 2ll);
        }
    }
    vector<int8_t> memo(mx+1, -1);
    for(int qi = 0; qi < qq; ++qi) {
        if(memo[q[qi]] != -1) {
            cout << (memo[q[qi]] ? "YES\n" : "NO\n");
            continue;
        }
        bool y = 0;
        for(int i = 0; i < (int)divs[q[qi]].size(); ++i) {
            int d = divs[q[qi]][i];
            if(!ways[d]) continue;
            for(int j = i; j < (int)divs[q[qi]].size(); ++j) {
                int d1 = divs[q[qi]][j];
                if(!ways[d1])  continue;
                if(lcm(d, d1) == q[qi]) {
                    if(d != d1 || ways[d] == 2) {
                        y = 1;
                        goto nxt;
                    }
                }
            }
        }
        nxt:;
        cout << (y ? "YES\n" : "NO\n");
        memo[q[qi]] = y;
    }
}

signed main() {
	cin.tie(0)->sync_with_stdio(0), cout.tie(0);
	int ttt{1};
	//cin >> ttt;
	while(ttt--) solve();
}
