#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    int n, q; cin >> n >> q;
    vector<pair<int, long long> > c(n + 1, make_pair(0, 0));
    for (int i = 1; i <= n; ++i) {
        cin >> c[i].second >> c[i].first;
    }
    sort(c.begin(), c.end());
    vector<long long> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) a[i] = a[i - 1] + c[i].second;
    for (long long p, k; q--; ) {
        cin >> k;
        p = lower_bound(a.begin(), a.end(), k) - a.begin();
        cout << c[p].first << '\n';
    }
    return 0;
}
