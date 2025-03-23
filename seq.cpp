#include <bits/stdc++.h>
using namespace std;
const int MAXN = 106;
struct tSeg {
	int a[106], l;
	tSeg() { l = 0, memset(a, 0, sizeof a); }
} base[MAXN], ans[MAXN];
tSeg mul(tSeg x, tSeg y) {
	tSeg r; r.l = x.l + y.l;
	for (int i = 0; i <= x.l; ++i)
		for (int j = 0; j <= y.l; ++j)
			r.a[i + j] += x.a[i] * y.a[j];
	return r;
}
tSeg add(tSeg x, tSeg y) {
	tSeg r; r.l = max(x.l, y.l);
	for (int i = 0; i <= r.l; ++i)
		r.a[i] = x.a[i] + y.a[i];
	return r;
}
void output(tSeg x) {
	for (int i = x.l; ~i; --i) {
		if (!x.a[i]) continue;
		if (i != x.l) putchar(x.a[i] > 0 ? '+' : '-');
		if (abs(x.a[i]) != 1) printf("%d", abs(x.a[i]));
		if (i) printf("n^%d", i);
	}
}
int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int n; scanf("%d", &n);
	for (int i = 0; i <= n; ++i)
		base[i].a[base[i].l = 0] = 1;
	for (int i = 1; i <= n; ++i) {
		tSeg pt;
		pt.l = 1;
		pt.a[1] = 1;
		pt.a[0] = -(i - 1);
		base[i] = mul(base[i - 1], pt);
		// output(base[i]);
		// putchar('\n');
	}
	for (int k = 1; k <= n; ++k) {
		int cnt = 1;
		ans[k] = base[k];
		for (int i = k - 1; ~i; --i) {
			cnt <<= 1;
			tSeg co;
			co.a[co.l = 0] = -cnt * base[k].a[i];
			ans[k] = add(ans[k], mul(ans[i], co));
		}
		printf("%d: (", k);
		output(ans[k]);
		printf(")*2^n-%d\n", k);
	}
	return 0;
}