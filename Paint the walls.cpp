#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[100005];
int n, s;
int sum(int i, int j) {
	if (i == 0) return a[j];
	return a[j] - a[i - 1];
}
int first_sum(int x, int y) {
	int res1 = y * (y + 1) / 2;
	int res2 = x * (x + 1) / 2;
	return res1 - res2;
}
int solve(int start, int mid) {
	if (start > mid) return s + 100;
	int res = sum(start, mid);
	int cnt = mid - start + 1;
	res += (cnt * first_sum(start, mid + 1));
	return res;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i) a[i] += a[i - 1];
	}
	int ans = 0;
	for (int start = 0; start < n; start++) {
		int res = -1;
		int low = start, high = n - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (solve(start, mid) <= s)
				res = mid, low = mid + 1;
			else
				high = mid - 1;
		}
		ans = max(ans, res - start + 1);
	}

	cout << ans << "\n";

}