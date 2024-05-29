#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    while (q--) {
        int x; cin >> x;
        int p = lower_bound(a.begin(), a.end(), x) - a.begin();
        cout << p << '\n';
    }
    return 0;
}
