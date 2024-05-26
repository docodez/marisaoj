#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> e(n), s(n);
    int smx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> e[i] >> s[i];
        e[i] += s[i];
        smx = max(smx, s[i]);
    }
    sort(e.begin(), e.end(), greater<int>());
    long long ans = 0;
    for (int i = 0; i < n && q && e[i] > smx; ++i, --q) {
        ans += e[i];
    }
    ans += 1ll * smx * q;
    cout << ans;
    return 0;
}
