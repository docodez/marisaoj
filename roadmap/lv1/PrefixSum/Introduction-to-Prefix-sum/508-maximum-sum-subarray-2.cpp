#include <bits/stdc++.h>
using namespace std;

const long long oo = 1e15;
const int maxn = 1e5 + 5;

int n;
int a[maxn];
long long mxl[maxn], mxr[maxn];

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	long long ml = 0, mr = 0;
	mxl[0] = mxr[n + 1] = -oo;
	for (int i = 1; i <= n; ++i) {
		ml += a[i];
		mxl[i] = max(mxl[i - 1], ml);
		ml = max(ml, 0ll);

		mr += a[n - i + 1];
		mxr[n - i + 1] = max(mxr[n - i + 2], mr);
		mr = max(mr, 0ll);
	}
	long long ans = -oo;
	for (int i = 1; i < n; ++i) {
		ans = max(ans, mxl[i] + mxr[i + 1]);
	}
	cout << ans;
	return 0;
}
