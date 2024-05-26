#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 1;

bool ip[maxn];

void sieve(int N = maxn) {
  ip[1] = true;
  for (int i = 2; i * i <= N; ++i) if (!ip[i]) {
    for (int j = i * i; j <= N; j += i) ip[j] = true;
  }
}

int main() {
  #define taskname ""
  if (fopen (taskname".inp", "r")) {
    freopen (taskname".inp", "r", stdin);
    freopen (taskname".out", "w", stdout);
  }
  ios::sync_with_stdio(NULL); cin.tie(0);
  sieve();
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) if (!ip[i]) cout << i << ' ';
  return 0;
}
  
