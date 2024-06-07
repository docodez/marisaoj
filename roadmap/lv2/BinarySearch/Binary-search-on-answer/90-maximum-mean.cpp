#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

int n, k;
double a[maxn], c[maxn];

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    double l = 0, r = 1e9 + 1;
    for (int _ = 0; _ < 100; ++_) {
        double mid = (l + r) / 2;

        bool ok = false;
        for (int i = 1; i <= n; ++i) c[i] = c[i - 1] + a[i] - mid;
        double mn = 0;
        for (int i = k; i <= n; ++i) {
            mn = min(mn, c[i - k]);
            if (c[i] - mn >= 0) {
                ok = true;
                break;
            }
        }

        if (ok) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(12) << l;
    return 0;
}
