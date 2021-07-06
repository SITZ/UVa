#include <bits/stdc++.h>

using namespace std;

int stk[65536], top;
int use[256];
char fmt[256][16];

int store()
{
	int i;
	for (i = '0'; i <= '9'; i++)
		if (use[i] == 0)
		{
			break;
		}
	use[i] = 1;
	printf("ST $%c\n", i);
	return i;
}

void take(int k)
{
	int i;
	top -= k;
	for (i = 0; i < top; i++)
	{
		if (stk[i] == 0)
		{
			stk[i] = store();
			break;
		}
	}
	for (i = 0; i < top; i++)
		if (isalpha(stk[i]))
		{
			break;
		}
	if (i >= top)
	{
		return;
	}
	for (i = 0; i < k; i++)
	{
		if (stk[top + i] == 0)
		{
			stk[top + i] = store();
			break;
		}
	}
	for (i = 0; i < top; i++)
	{
		if (isalpha(stk[i]))
		{
			printf("L %s\n", fmt[stk[i]]);
			stk[i] = store();
		}
	}
}

void commut(char op)
{
	int x, y;
	take(2);
	x = stk[top];
	y = stk[top + 1];
	if (x == 0)
	{
		printf("%c %s\n", op, fmt[y]);
	}
	else if (y == 0)
	{
		printf("%c %s\n", op, fmt[x]);
	}
	else
	{
		printf("L %s\n%c %s\n", fmt[x], op, fmt[y]);
	}
	use[x] = 0;
	use[y] = 0;
	stk[top++] = 0;
}

void sub()
{
	int x, y;
	take(2);
	x = stk[top];
	y = stk[top + 1];
	if (x == 0)
	{
		printf("S %s\n", fmt[y]);
	}
	else if (y == 0)
	{
		printf("N\nA %s\n", fmt[x]);
	}
	else
	{
		printf("L %s\nS %s\n", fmt[x], fmt[y]);
	}
	use[x] = 0;
	use[y] = 0;
	stk[top++] = 0;
}

void div()
{
	int x, y;
	take(2);
	x = stk[top];
	y = stk[top + 1];
	if (x == 0)
	{
		printf("D %s\n", fmt[y]);
	}
	else if (y == 0)
	{
		/* reg <- x / reg */
		y = store();
		printf("L %s\nD %s\n", fmt[x], fmt[y]);
	}
	else
	{
		printf("L %s\nD %s\n", fmt[x], fmt[y]);
	}
	use[x] = 0;
	use[y] = 0;
	stk[top++] = 0;
}

void neg()
{
	take(1);
	if (stk[top] == 0)
	{
		printf("N\n");
	}
	else
	{
		printf("L %s\nN\n", fmt[stk[top]]);
	}
	use[stk[top]] = 0;
	stk[top++] = 0;
}

int main()
{
	static char line[65536];
	char *p;
	int i, t;
	for (i = 0; i <= 255; i++)
	{
		sprintf(fmt[i], "%c", i);
	}
	for (i = '0'; i <= '9'; i++)
	{
		sprintf(fmt[i], "$%c", i);
	}
	for (t = 0; gets(line);)
	{
		if (t++ != 0)
		{
			printf("\n");
		}
		memset(use, 0, sizeof(use));
		for (top = 0, p = line; *p; p++)
		{
			if (isalpha(*p))
			{
				stk[top++] = *p;
			}
			else if (*p == '+' || *p == '*')
			{
				commut((*p == '+') ? 'A' : 'M');
			}
			else if (*p == '-')
			{
				sub();
			}
			else if (*p == '/')
			{
				div();
			}
			else if (*p == '@')
			{
				neg();
			}
		}
		if (top > 0 && stk[top - 1] != 0)
		{
			printf("L %s\n", fmt[stk[top - 1]]);
		}
	}
	return 0;
}
