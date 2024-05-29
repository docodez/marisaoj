#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    int n, l, r; cin >> n >> l >> r;
    vector<int> a(n);   for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
        int L = lower_bound(a.begin(), a.end(), l - a[i]) - a.begin();
        int R = upper_bound(a.begin(), a.end(), r - a[i]) - a.begin();
        cnt += (R - L) - (L <= i && i < R);
    }
    cout << cnt / 2;
    return 0;
}
