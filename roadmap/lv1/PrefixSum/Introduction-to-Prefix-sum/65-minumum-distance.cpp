#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int n;
int a[maxn], b[maxn * 3];
long long sum[maxn * 3], sL[maxn * 3], sR[maxn * 3];

int main() {
  clock_t tStart = clock();
  ios::sync_with_stdio(NULL);  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int l = (n - 1) / 2, r = n / 2, m = l + n + r;
  for (int i = 1; i <= l; ++i) b[i] = a[n - (l - i + 1) + 1];
  for (int i = 1; i <= n; ++i) b[l + i] = a[i];
  for (int i = 1; i <= r; ++i) b[l + n + i] = a[i];
  for (int i = 1; i <= m; ++i) {
    sum[i] = sum[i - 1] + b[i];
  }
  for (int i = 1; i <= m; ++i) {
    sL[i] = sL[i - 1] + sum[i];
    sR[m - i + 1] = sR[m - i + 2] + sum[m] - sum[m - i];
  }
  long long ans = 1e18;
  for (int i = l + 1; i <= l + n; ++i) {
    long long scur = 
      sL[i - 1] - sL[i - l - 1] - sum[i - l - 1] * l +
      sR[i + 1] - sR[i + r + 1] - (sum[m] - sum[i + r]) * r;
    ans = min(ans, scur);
  }
  cout << ans;

  cerr << '\n' << fixed << setprecision(10) << (double) (clock() - tStart)/CLOCKS_PER_SEC << '\n';
  return 0;
}
