#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    while (q--) {
        int x; cin >> x;
        int p = upper_bound(a.begin(), a.end(), x) - a.begin();
        if (p == 1) cout << "-1\n";
        else cout << p - 1 << '\n';
    }
    return 0;
}
