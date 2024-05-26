#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int n;
int a[maxn];
long long g[maxn][4], f[maxn][4];

int main() {
  ios::sync_with_stdio(NULL);  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];

    for (int k = 1; k <= 3; ++k) {
      g[i][k] = max(g[i - 1][k], f[i - 1][k - 1]) + a[i];
      f[i][k] = max(f[i][k - 1], max(g[i][k], f[i - 1][k]));
    }
  }
  cout << f[n][3];
  return 0;
}
