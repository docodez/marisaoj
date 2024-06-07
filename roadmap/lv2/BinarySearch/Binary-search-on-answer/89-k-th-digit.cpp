#include <bits/stdc++.h>
using namespace std;

vector<long long> dig(1, 0);
vector<long long> p10(1, 1);

int lg(long long x) {
    int k = 0;
    while (x) x /= 10, ++k;
    return k;
}

void init() {
    for (; dig.back() < 1e18 ; p10.push_back(p10.back() * 10)) {
        dig.push_back(dig.back() + p10.back() * 9 * p10.size());
        if (p10.size() > 19) break;
    }
}

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    init();
    long long k; cin >> k;
    long long l = 0, r = 1e17 + 1;
    int len;
    long long cur;
    while (r - l > 1) {
        long long mid = l + r >> 1;

        len = lg(mid);
        cur = dig[len - 1] + (mid - p10[len - 1] + 1) * len;

        if (cur < k) l = mid;
        else r = mid;
    }
    len = lg(l);
    cur = dig[len - 1] + (l - p10[len - 1] + 1) * len;
    cout << to_string(r)[k - cur - 1];
    return 0;
}
