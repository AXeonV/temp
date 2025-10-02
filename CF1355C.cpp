#include <iostream>
using namespace std;
using ll = long long;
const int MAXN = 5e5;
ll Z[MAXN * 2 + 6], sZ[MAXN * 2 + 6];
int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int A, B, C, D;
	scanf("%d%d%d%d", &A, &B, &C, &D);
	int cnt = 0; ll ans = 0;
	for (int i = C; i <= D; ++i) Z[i] = ++cnt;
	for (int i = D + 1; i <= MAXN * 2; ++i) Z[i] = Z[i - 1];
	for (int i = C; i <= MAXN * 2; ++i) sZ[i] = sZ[i - 1] + Z[i];
	for (int x = A; x <= B; ++x) {
		int lb = x + B - 1, rb = x + C - 1;
		ans += sZ[rb] - sZ[lb - 1];
	}
	printf("%lld\n", ans);
	return 0;
}