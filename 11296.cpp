#include <bits/stdc++.h>

using namespace std;

int main()
{
	for (long long n; scanf("%lld", &n) == 1; n = (n + 2) >> 1, printf("%lld\n", ((n + 1) * n) >> 1))
		;
	return 0;
}
