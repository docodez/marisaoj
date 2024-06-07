#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int l = 1, r = a[n - 1] - a[0] + 1;
    while (r - l > 1) {
        int mid = l + r >> 1;

        int cnt = 1, last = a[0];
        for (int i = 1; i < n && cnt < k; ++i) {
            if (a[i] - last >= mid) {
                last = a[i];
                ++cnt;
            }
        }

        if (cnt == k) l = mid;
        else r = mid;
    }
    cout << l;
    return 0;
}
