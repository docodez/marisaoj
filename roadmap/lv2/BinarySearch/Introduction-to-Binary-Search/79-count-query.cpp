#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    int n, q;   cin >> n >> q;
    vector<vector<int> > a((int) 1e5 + 1, vector<int>(0));
    for (int x, i = 1; i <= n; ++i) {
        cin >> x;
        a[x].push_back(i);
    }
    for (int l, r, k; q--; ) {
        cin >> l >> r >> k;
        int L = lower_bound(a[k].begin(), a[k].end(), l) - a[k].begin();
        int R = upper_bound(a[k].begin(), a[k].end(), r) - a[k].begin() - 1;
        cout << R - L + 1 << '\n';
    }
    return 0;
}
