#include <vector>
int countWays(int n, int m, std::vector<int> S) {
	std::vector<int> dp(n+1, 0);
	int mod = 1e9+7;
	dp[0] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int s : S) {
			if(i-s >= 0) dp[i] = (dp[i] + dp[i-s]) % mod;
		}
	}
	return dp[n];
}
