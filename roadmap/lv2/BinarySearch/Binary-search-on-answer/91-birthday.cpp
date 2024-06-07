#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    long long n, k; cin >> n >> k;
    vector<long long> a(n);   for (int i = 0; i < n; ++i) cin >> a[i], a[i] *= a[i];
    double l = 0, r = 1e10 + 1;
    for (int _ = 0; _ < 100; ++_) {
        double mid = (l + r) / 2.0;

        long long cn = 0;
        for (int i = 0; i < n; ++i) cn += a[i] / mid;

        if (cn >= k) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(6) << l;
    return 0;
}
