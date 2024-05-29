#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    long long n, k; cin >> n >> k;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];
    long long cnt = 0;
    for (int i = 0; i <= n; ++i) {
        int p = lower_bound(a.begin(), a.end(), a[i] + k) - a.begin();
        cnt += n - p + 1;
    }
    cout << cnt;
    return 0;
}
