#include <bits/stdc++.h>

using namespace std;

static int isalp[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static int go(char *s)
{
	static int c[256], g, n;
	register int i;
	for (i = 'a'; i <= 'z'; i++)
	{
		c[i] = 0;
	}
	for (i = 'A'; i <= 'Z'; i++)
	{
		c[i] = 0;
	}
	for (n = 0, g = 0; *s; s++)
	{
		if (isalp[(int)*s])
		{
			c[*s] ^= 1;
			n++;
		}
		else if (*s == '=')
		{
			if (n-- < 2)
			{
				return 0;
			}
		}
		else if (*s == '-')
		{
			if (n < 1)
			{
				return 0;
			}
			g ^= 1;
		}
		else
		{
			return 0;
		}
	}
	if (n != 1)
	{
		return 0;
	}
	if (g)
	{
		return 1;
	}
	for (i = 'a'; i <= 'z'; i++)
	{
		if (c[i])
		{
			return 1;
		}
	}
	for (i = 'A'; i <= 'Z'; i++)
	{
		if (c[i])
		{
			return 1;
		}
	}
	return 2;
}

int main()
{
	static char s[512];
	static const char *r[] = {"incorrect\n", "formula\n", "tautology\n"};
	static int t;
	while (gets(s) && sscanf(s, "%d", &t) != 1)
		;
	while (t-- > 0 && gets(s))
	{
		printf(r[go(s)]);
	}
	return 0;
}
