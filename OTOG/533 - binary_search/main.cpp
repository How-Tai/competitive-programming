#include "binary_search.h"

signed main() {
	unsigned long long n = get_n(), l = 0, r = n-1, mid;
	int i = 1;
	while(l <= r && i <= 50) {
		mid = l + (r - l) / 2;
		if(is_less(mid)) {
			l = mid + 1;
		}
		else if(is_equal(mid)) {
			answer(mid);
			return 0;
		}
		else {
			r = mid - 1;
		}
		++i;
	}
	for(; l <= r; ++l) {
		if(is_equal(l)) {
			answer(l);
			return 0;
		}
	}
}
