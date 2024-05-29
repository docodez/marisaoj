#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    set<long long> s(a.begin(), a.end());
    a = vector<long long>(s.begin(), s.end());
    int l = -1, r = lower_bound(a.begin(), a.end(), a[0] + n) - a.begin();
    int ans = n;
    while (l < r) {
        ++l;
        while (r < a.size() && a[r] < a[l] + n) ++r;
        ans = min(ans, n - (r - l));
    }
    cout << ans;
    return 0;
}
