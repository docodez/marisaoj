#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int n;
int x[maxn], y[maxn];

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    sort(x, x + n);
    sort(y, y + n);
    long long ans = 0;
    for (int i = 0; i < n / 2; ++i) {
        ans += x[n / 2] - x[i] + y[n / 2] - y[i];
    }
    for (int i = n / 2; i < n; ++i) {
        ans += x[i] - x[n / 2] + y[i] - y[n / 2];
    }
    cout << ans;
    return 0;
}
