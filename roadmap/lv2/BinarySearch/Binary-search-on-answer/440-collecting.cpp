#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

int n, k;
double v[maxn], w[maxn], c[maxn];

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> v[i] >> w[i];
    double l = 0, r = 1e9 + 1;
    for (int _i = 0; _i < 100; ++_i) {
        double mid = (l + r) / 2;

        for (int i = 0; i < n; ++i) c[i] = v[i] - mid * w[i];
        sort(c, c + n, greater<double>());

        double sum = 0.0;
        for (int i = 0; i < k; ++i) sum += c[i];

        if (sum >= 0) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(12) << l;
    return 0;
}
