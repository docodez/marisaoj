#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 3;

int n;
pair<int, int> c[maxn];
int sum = 0, dp[maxn];

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i].first;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i].second;
        sum += c[i].second;
    }
    sort(c + 1, c + n + 1, [](const pair<int, int> &a, const pair<int, int> &b){
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    });
    for (int i = 1; i <= n; ++i) {
        for (int j = c[i].first; j > 0; --j) {
            dp[j] = max(dp[j], dp[j - 1] + c[i].second);
        }
        for (int j = c[i].first + 1; j <= 1000; ++j) dp[j] = max(dp[j], dp[j - 1]);
    }
    cout << sum - dp[c[n].first];
    return 0;
}
