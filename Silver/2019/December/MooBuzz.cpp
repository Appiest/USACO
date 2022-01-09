#include <iostream>

using namespace std;

int main() {
	freopen("moobuzz.in", "r", stdin);
	freopen("moobuzz.out", "w", stdout);

	int n; cin >> n;

	int res = 0;
	while (n - 8 > 0) {
		res += 15;
		n -= 8;
	}

	int plus[8] = {1, 2, 4, 7, 8, 11, 13, 14};

	cout << res + plus[n - 1] << '\n';
}

