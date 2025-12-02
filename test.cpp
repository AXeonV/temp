#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 6;
int a[MAXN];
int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int n; scanf("%d\n", &n);
	while (n) {
		int tot = 0;
		memset(a, 0, sizeof a);
		while (n) {
			a[++tot] = n & 1;
			n >>= 1;
		}
		int ans = tot - 1, cnt = 0;
		for (int i = 1; i <= tot; ++i)
			cout << a[i] << " ";
		cout << endl;
		for (int i = 1; i <= tot + 1; ++i) {
			if (a[i]) ++cnt;
			else {
				if (!cnt) continue;
				if (i == tot + 1) {
					if (cnt > 2) ans += 2;
					else ++ans;
				} else {
					if (cnt > 1) ans += 2;
					else ++ans;
				}
				cnt = 0;
			}
		}
		printf("%d\n", ans);
		scanf("%d", &n);
	}
	return 0;
}