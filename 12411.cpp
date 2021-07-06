#include <bits/stdc++.h>

using namespace std;

#define EPS (1e-9)

int n, K;
int A, B, p;

int main()
{
	int T;
	scanf("%d", &T);
	int ncase = 0;
	while (T--)
	{
		scanf("%d%d", &n, &K);
		A = B = p = 0;
		for (int i = 0; i < n; ++i)
		{
			int x;
			scanf("%d", &x);
			if (x > 0)
			{
				A += x, ++p;
			}
			else
			{
				B += -x;
			}
		}
		printf("Case %d: ", ++ncase);
		if (p == 0)
		{
			puts("-1.000");
			continue;
		}
		double ans = 1.0 * A / p + 1.0 * B / p;
		double f = 1.0 / (n * p);
		for (int i = 1; i <= K; ++i)
		{
			ans -= f * B;
			f *= 1.0 * (n - p - i) / (n - i);
		}
		printf("%.3lf\n", ans + EPS);
	}
	return 0;
}
