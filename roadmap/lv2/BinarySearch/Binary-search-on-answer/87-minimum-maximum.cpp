#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    long long n, k; cin >> n >> k;
    vector<long long> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];
    long long l = a[n] / k - 1, r = a[n];
    while (r - l > 1) {
        long long mid = l + r >> 1;

        int cnt = 0;
        for (int last = 0, i = 1; i <= n; ++i) {
            if (a[i] - a[last] > mid) {
                last = i - 1;
                if (a[i] - a[last] > mid) {
                    cnt = 1e9 + 7;
                    break;
                }
                ++cnt;
            }
        }
        if (cnt + 1 > k) l = mid;
        else r = mid;
    }
    cout << r;
    return 0;
}
