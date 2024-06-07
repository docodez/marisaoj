#include <bits/stdc++.h>
using namespace std;

long long getPos(long long x) {
    return (x/3) + (x/5) + (x/7) - (x/15) - (x/21) - (x/35) + (x/105);
}

long long get(long long k) {
    long long l = 0, r = 2e9;
    while (r - l > 1) {
        long long mid = l + r >> 1;
        if (getPos(mid) < k) l = mid;
        else r = mid;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    long long k; cin >> k;
    cout << get(k);
    return 0;
}
