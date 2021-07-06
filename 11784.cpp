#include <bits/stdc++.h>

using namespace std;

struct Door
{
	int x, y;
} dr[4040];

int top, bot, left_, right_, px, py, m, n, h, mintime, minstep;

void TinhD()
{
	top = px;
	bot = m - 1 - px;
	left_ = py;
	right_ = n - 1 - py;
}

void Escape(int len, int p)
{
	if (len + 1 < mintime || (len + 1 == mintime && p + 1 < minstep))
	{
		mintime = len + 1;
		minstep = p + 1;
	}
}

void Check_Top(int i)
{
	if (py - dr[i].y >= top)
	{
		Escape(py - dr[i].y, top);
	}
	else if (n - 1 - dr[i].y + top >= right_)
	{
		Escape(n - 1 - dr[i].y + top, right_);
	}
	else
	{
		Escape(n - 2 - dr[i].y + m + right_, bot);
	}
}

void Check_Right(int i)
{
	if (px - dr[i].x >= right_)
	{
		Escape(px - dr[i].x, right_);
	}
	else if (m - 1 - dr[i].x + right_ >= bot)
	{
		Escape(m - 1 - dr[i].x + right_, bot);
	}
	else
	{
		Escape(m - 2 - dr[i].x + n + bot, left_);
	}
}

void Check_Bot(int i)
{
	if (dr[i].y - py >= bot)
	{
		Escape(dr[i].y - py, bot);
	}
	else if (dr[i].y + bot >= left_)
	{
		Escape(dr[i].y + bot, left_);
	}
	else
	{
		Escape(dr[i].y + m - 1 + left_, top);
	}
}

void Check_Left(int i)
{
	if (dr[i].x - px >= left_)
	{
		Escape(dr[i].x - px, left_);
	}
	else if (dr[i].x + left_ >= top)
	{
		Escape(dr[i].x + left_, top);
	}
	else
	{
		Escape(dr[i].x + n - 1 + top, right_);
	}
}

void Find()
{
	for (int i = 1; i <= h; i++)
	{
		if (dr[i].x == 0)
		{
			Check_Top(i);
		}
		else if (dr[i].y == n - 1)
		{
			Check_Right(i);
		}
		else if (dr[i].x == m - 1)
		{
			Check_Bot(i);
		}
		else
		{
			Check_Left(i);
		}
	}
}

int main()
{
	scanf("%d%d%d", &m, &n, &h);
	while (m != 0 && n != 0 && h != 0)
	{
		for (int i = 1; i <= h; i++)
		{
			scanf("%d %d", &dr[i].x, &dr[i].y);
		}
		scanf("%d %d", &px, &py);
		TinhD();
		mintime = minstep = 500000;
		Find();

		printf("%d %d\n", mintime, minstep);
		scanf("%d %d %d", &m, &n, &h);
	}
	return 0;
}
