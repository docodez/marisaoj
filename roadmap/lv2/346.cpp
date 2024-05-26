#include <bits/stdc++.h>
using namespace std;

int n;
long long k;
long long a[25];

string ans = "NO";

void Try(int x, long long l) {
  if (l == 0) ans = "YES";
  if (x == n) return;
  for (int i = x + 1; i <= n; ++i) if (a[i] <= l) {
    Try(i, l - a[i]);
  }
}

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  Try(0, k);
  cout << ans;
}

int main() {
  #define taskname ""
  if (fopen (taskname".inp", "r")) {
    freopen (taskname".inp", "r", stdin);
    freopen (taskname".out", "w", stdout);
  }
  ios::sync_with_stdio(NULL); cin.tie(0);
  int tt;
  tt = 1;
  // cin >> tt;
  while (tt--) solve();
  return 0;
}
  
