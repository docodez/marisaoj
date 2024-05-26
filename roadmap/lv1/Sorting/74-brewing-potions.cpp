#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

int n, k;
int a[maxn];

int main() {
	ios::sync_with_stdio(NULL);	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1, r = n;
	int d = 0;
	while (l < r) {
		if (a[l] + a[r] <= k) {
			++d;
			++l;
			--r;
		} else {
			++d;
			--r;
		}
	}
	if (l == r) ++d;
	cout << d;
	return 0;
}
