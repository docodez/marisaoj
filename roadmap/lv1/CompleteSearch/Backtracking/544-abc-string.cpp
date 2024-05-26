#include <bits/stdc++.h>
using namespace std;

void go(int n, string s) {
	if (n == 0) return void(cout << s << '\n');
	for (char x = 'A'; x <= 'C'; ++x) if (x != s.back()) go(n - 1, s + x);
}

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	int n; cin >> n;
	go(n, "");
	return 0;
}
