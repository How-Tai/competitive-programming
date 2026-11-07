#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000005;

// Fast input: non-negative integers and char only
struct Reader {
    static constexpr int SZ = 1 << 20;
    char buf[SZ]; int at = 0, len = 0;
    inline char get() { if (at == len) { len = fread(buf, 1, SZ, stdin); at = 0; if (!len) return 0; } return buf[at++]; }
    inline int number() { char c = get(); while (c && c <= ' ') c = get(); int x = 0; while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = get(); } return x; }
};

// Fast output: non-negative 64-bit integers and char
struct Writer {
    static constexpr int SZ = 1 << 20;
    char buf[SZ]; int at = 0;
    inline void flush() { if (at) fwrite(buf, 1, at, stdout); at = 0; }
    inline void ch(char c) { if (at == SZ) flush(); buf[at++] = c; }
    inline void num(long long x) { char s[24]; int p = 0; do { s[p++] = '0' + x % 10; x /= 10; } while (x); while (p) ch(s[--p]); }
    ~Writer() { flush(); }
};


Reader in;
Writer out;

int main() {

    int n = in.number();
    vector<int> a(n), sufmx(n, -(7ll << 58));
    vector<long long> sufsum(n);
    for (int i = 0; i < n; i++) a[i] = in.number();

    sufmx[n-1] = sufsum[n-1] = a[n-1];
    for(int i = n-2; i >= 0; --i) {
        sufmx[i] = max(sufmx[i+1], a[i]);
        sufsum[i] = sufsum[i+1];
        if(a[i] > sufmx[i+1]) sufsum[i] += a[i];
    }

    vector<long long> stk;
    long long sum{0}, k{0};

    for(int i = 0; i < n; ++i) {
        long long mx = (i+1 == n ? -(7ll << 58) : sufmx[i+1]);
        while(k < (int)stk.size() && stk[k] > mx) sum += stk[k++];
        out.num(sum + (i+1==n ? 0 : sufsum[i+1]));
        out.ch(' ');
        while(!stk.empty() && stk.back() <= a[i]) {
            if((int)stk.size() <= k) sum -= stk.back(), --k;
            stk.pop_back();
        }
        stk.push_back(a[i]);
        if(a[i] > mx) sum += a[i], ++k;
    }
    return 0;
}
