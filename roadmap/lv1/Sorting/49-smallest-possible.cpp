#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[10] = {};

int main() {
	ios::sync_with_stdio(NULL);	cin.tie(0);
	cin >> s;
	for (char &x : s) ++cnt[x - '0'];
	for (int i = 1; i < 10; ++i) if (cnt[i] != 0) {
		cout << i;
		--cnt[i];
		break;
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < cnt[i]; ++j) cout << i;
	}
	return 0;
}
