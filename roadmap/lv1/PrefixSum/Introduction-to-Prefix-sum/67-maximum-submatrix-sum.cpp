#include <bits/stdc++.h>
using namespace std;

const int maxn = 555;

int n, m;
int a[maxn][maxn];
long long pre[maxn][maxn];
vector<long long> v;

long long kadane(const vector<long long> &a) {
  long long curSum = 0, mxSum = 0;
  for (int i = 0; i < a.size(); ++i) {
    curSum += a[i];
    if (curSum < 0) curSum = 0;
    else mxSum = max(mxSum, curSum);
  }
  return mxSum;
}

int main() {
  ios::sync_with_stdio(NULL);  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      pre[i][j] = pre[i][j - 1] + a[i][j];
    }
  }
  long long maxSum = -(1e18);
  for (int i = 1; i <= m; ++i) {
    for (int j = i; j <= m; ++j) {
      v.clear();
      for (int k = 1; k <= n; ++k) {
        v.push_back(pre[k][j] - pre[k][i - 1]);
      }
      maxSum = max(maxSum, kadane(v));
    }
  }
  cout << maxSum;
  return 0;
}
