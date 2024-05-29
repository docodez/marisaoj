#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(NULL);    cin.tie(0);
    string a, b;    cin >> a >> b;
    int A = a.size(), B = b.size();
    vector<vector<int> > p(26, vector<int>(0));
    for (int i = 0; i < A; ++i) p[a[i] - 'a'].push_back(i);
    long long ans = 0;
    for (int i = 0; i < B; ++i) {
        int c = b[i] - 'a';
        int l = lower_bound(p[c].begin(), p[c].end(), i) - p[c].begin();
        int r = upper_bound(p[c].begin(), p[c].end(), A - (B - i)) - p[c].begin();
        ans += r - l;
    }
    cout << ans;
    return 0;
}
