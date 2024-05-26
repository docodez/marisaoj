#include <bits/stdc++.h>
using namespace std;

int main() {
  clock_t tStart = clock();
  ios::sync_with_stdio(NULL);  cin.tie(0);
  int n; cin >> n;
  vector<tuple<int, int, int> > a;
  for (int x, y, z, i = 0; i < n; ++i) {
    cin >> x >> y >> z;
    a.push_back(make_tuple(x, y, z));
  }
  sort(a.begin(), a.end());
  for (tuple<int, int, int> &x : a) cout << get<0>(x) << ' ' << get<1>(x) << ' ' << get<2>(x) << '\n';

  cerr << '\n' << fixed << setprecision(10) << (double) (clock() - tStart)/CLOCKS_PER_SEC << '\n';
  return 0;
}
