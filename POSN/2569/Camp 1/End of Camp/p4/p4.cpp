#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int ttt;
    cin >> ttt;
    while(ttt--) {
        int n;
        string s;
        cin >> n >> s;
        vector<char> stk;
        stk.reserve(n);
        int8_t y = 1;
        int mx = 0;
        int idx = n;
        for(int i = 0; i < n; ++i) {
            if('a' <= s[i] && s[i] <= 'z') stk.push_back(s[i]);
            else if('A' <= s[i] && s[i] <= 'Z') {
                if(stk.back() != tolower(s[i])) { y = 0; idx = i; break; }
                else stk.pop_back();
            }
            mx = max(mx, (int)stk.size());
        }
        if(!y || !stk.empty()) {
            cout << "No " << idx + 1;
        }
        else cout << "Yes " << mx;
        cout << (ttt ? "\n" : "");
    }
}
