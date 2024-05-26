#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	int n; cin >> n;
	vector<string> a(n);
	for (string &x : a) cin >> x;
	sort(a.begin(), a.end(), [](string &x, string &y){
		return (x + y) > (y + x);
	});
	for (string &x : a) cout << x;
	return 0;
}
