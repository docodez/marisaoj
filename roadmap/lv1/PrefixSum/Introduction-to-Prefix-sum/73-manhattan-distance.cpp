#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 1;

int n, k;
int a[maxn][maxn];
long long b[2 * maxn][2 * maxn];

int u(int x) {
  if (x < 0) return 0;
  if (x >= 2 * n) return 2 * n - 1;
  return x;
}

int main() {
  ios::sync_with_stdio(NULL);  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      b[i + j - 1][n - i + j] = a[i][j];
    }
  }
  for (int i = 1; i <= 2 * n; ++i) {
    for (int j = 1; j <= 2 * n; ++j) {
      b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
    }
  }
  for (int x = 1; x <= n; ++x) {
    for (int y = 1; y <= n; ++y) {
      int i = x + y - 1, j = n - x + y;
      cout << b[u(i + k)][u(j + k)] - b[u(i + k)][u(j - k - 1)] - b[u(i - k - 1)][u(j + k)] + b[u(i - k - 1)][u(j - k - 1)] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
