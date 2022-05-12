#include <bits/stdc++.h>

#define ll long long
#define v vector

using namespace std;

/*
DP over all cities for t = 0 all the way to t = 1000. 
This limit works because if each city gives 1000 moonies, 
1000t - t^2 < 0. Keep track of the maximum for each time period.
*/

int n, m, c;
v<int> cities(1005);
v<int> edges[1005];
v<v<ll>> dp(1005, v<ll>(1005, -1));

int main() {
	freopen("time.in", "r", stdin);
	freopen("time.out", "w", stdout);

	cin >> n >> m >> c;
	for (int i = 0; i < n; i++) cin >> cities[i];
	
	for (int i = 0; i < m; i++) {
		int a, b; 
		cin >> a >> b;

		edges[--a].push_back(--b);
	}

	ll res = 0;

	dp[0][0] = 0;
	for (int t = 0; t < 1001; t++) {
		for (int i = 0; i < n; i++) {
			if (dp[t][i] != -1) {
				for (int next : edges[i]) {
					dp[t + 1][next] = max(dp[t + 1][next], dp[t][i] + cities[next]);
				}
			}
		}
		res = max(res, dp[t][0] - c * t * t);
	}

	cout << res << '\n';
}
