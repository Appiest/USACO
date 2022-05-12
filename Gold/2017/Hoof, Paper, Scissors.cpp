#include <bits/stdc++.h>

#define v vector

using namespace std;

int n, k;
// H = 0
// P = 1
// S = 2
v<int> opp(100005);
// dp[game][k-count][current guesture]
v<v<v<int>>> dp(100005, v<int>(21, v<int>(3, 0)));

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		char c; cin >> c;

		if      (c == 'H') 	opp[i] = 0;
		else if (c == 'P')  opp[i] = 1;
		else 				opp[i] = 2;
	}

	int winning[] = {1, 2, 0};
	for (int i = 1; i <= n; i++) {
		for (int nk = 0; nk < k - 1; nk++) {
			// do dp here
			dp[n][nk][winning[opp[n]]] = 0; // wrong
			
		}
	}

	int res = 0;
	for (int nk = 0; nk < k - 1; nk++) {
		for (int move = 0; move < 3; move++) {
			res = max(res, dp[n][nk][move]);
		}
	}

	cout << res << '\n';
}
