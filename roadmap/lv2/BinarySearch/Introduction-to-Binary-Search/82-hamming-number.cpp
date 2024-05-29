#include <bits/stdc++.h>
using namespace std;

const long long oo = 1e18;

vector<long long> h(1, 0);

void init() {
    for (long long x = 1; x <= oo; x *= 2) {
        for (long long y = 1; x * y <= oo; y *= 3) {
            for (long long z = 1; x * y * z <= oo; z *= 5) {
                h.push_back(x * y * z);
            }
        }
    }
    sort(h.begin(), h.end());
}

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    init();
    int tt; cin >> tt;
    while (tt--) {
        long long m; cin >> m;
        int p = lower_bound(h.begin(), h.end(), m) - h.begin();
        if (h[p] != m) cout << "-1\n";
        else cout << p << '\n';
    }
    return 0;
}
