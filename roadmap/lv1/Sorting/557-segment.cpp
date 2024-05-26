#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int n;
pair<int, int> s[maxn];
int a[maxn];
int dp[maxn];

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i].second >> s[i].first;
    }
    sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] = s[i].first;
        int p = lower_bound(a + 1, a + i, s[i].second) - a - 1;
        dp[i] = max(dp[i - 1], dp[p] + 1);
    }
    cout << dp[n];
    return 0;
}
