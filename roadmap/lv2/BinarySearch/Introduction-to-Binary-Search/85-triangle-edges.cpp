#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);   for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    long long cnt = 0;
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int L = upper_bound(a.begin() + j + 1, a.end(), a[j] - a[i]) - a.begin();
            int R = lower_bound(a.begin() + j + 1, a.end(), a[j] + a[i]) - a.begin();
            cnt += R - L;
        }
    }
    cout << cnt;
    return 0;
}
