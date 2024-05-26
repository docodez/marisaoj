#include <bits/stdc++.h>
using namespace std;

int n, k;
int p[25];

void pr() {
  for (int i = 1; i <= k; ++i) cout << p[i] << ' ';
  cout << '\n';
}

void Try(int i) {
  if (i > k) return pr();
  for (int j = p[i - 1] + 1; j <= n; ++j) {
    p[i] = j;
    Try(i + 1);
  }
}

void solve() {
  cin >> n >> k;
  Try(1);
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
  
