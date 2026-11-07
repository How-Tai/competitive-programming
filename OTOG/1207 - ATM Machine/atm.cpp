#include "atm.h"

int findBalance() {
    int l = 0, r = 1e9;
    int withdrawn = 0;
    while(l < r) {
        int mid = l + (r - l + 1) / 2;
        int res = withdraw(mid - withdrawn);
        if(res == 2) return mid;
        else if(res == 1) {
            withdrawn = mid;
            l = mid+1;
        }
        else r = mid - 1;
    }
    return r;
}
