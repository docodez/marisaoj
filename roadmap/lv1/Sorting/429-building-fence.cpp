#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    int n;  cin >> n;
    vector<pair<long long, long long> > a(n + 1);
    vector<long long> b(n + 1);
    long long sum = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i].first;
    for (int i = 1; i <= n; ++i) cin >> a[i].second, b[i] = a[i].second;
    sort(a.begin() + 1, a.end(), [](const pair<int, int> &x, const pair<int, int> &y){
        return x.first > y.first || (x.first == y.first & x.second < y.second);
    });
    sort(b.begin() + 1, b.end(), greater<int>());
    for (long long i = 0, j = 1, sum = 0, t = 0; t < n; ++i, ++t) {
        if (a[i].second == b[j]) {
            if (i == n || a[i].first + b[j + 1] >= a[i + 1].first + b[j]) ++j;
            else ++i;
        }
//        cout << i << ' ' << j << ' ' << sum << '\n';
        cout << (sum += a[i].first) + b[j] << '\n';
    }
    return 0;
}
