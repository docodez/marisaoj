#include <bits/stdc++.h>
using namespace std;

long long get(long long n, long long m, long long k) {
    long long l = 0, r = n * m + 1;
    while (r - l > 1) {
        long long mid = l + r >> 1;

        long long cnt = 0;
        for (int i = 1; i <= n && i <= mid; ++i) {
            cnt += min(mid / i, 1ll * m);
        }
        if (cnt < k) l = mid;
        else r = mid;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    long long n, m, k; cin >> n >> m >> k;
    cout << get(n, m, k);
    return 0;
}
