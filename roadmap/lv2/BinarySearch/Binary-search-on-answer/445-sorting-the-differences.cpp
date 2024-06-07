#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    long long n, k; cin >> n >> k;
    k = n * (n - 1) / 2 - k + 1;
    vector<int> a(n);   for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        int mid = l + r >> 1;

        long long cnt = 0;
        for (int i = 0; i + 1 < n; ++i) {
            int p = lower_bound(a.begin(), a.end(), a[i] + mid) -  a.begin();
            cnt += n - p;
        }

        if (cnt >= k) l = mid;
        else r = mid;
    }
    cout << l;
    return 0;
}
