#include <bits/stdc++.h>

using namespace std;

char tm_[100];

#define eatNL cin.getline(tm_, sizeof(tm_));

struct Node
{
	char name[50];
	int win, winMLoss, totalPoint;
} teams[1020];

inline bool cmp(Node a, Node b)
{
	if (a.win != b.win)
	{
		return a.win > b.win;
	}
	else if (a.winMLoss != b.winMLoss)
	{
		return a.winMLoss > b.winMLoss;
	}
	else if (a.totalPoint != b.totalPoint)
	{
		return a.totalPoint > b.totalPoint;
	}
	return (strcmp(a.name, b.name) <= 0);
}

int searchTeams(char *_name, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (strcmp(_name, teams[i].name) == 0)
		{
			return i;
		}
	}
}

int main()
{
	char token[100], *name, *p, *name1, *name2;
	int t, m, i, j, index1, index2, temp1, temp2, win1, win2, p1, p2;
	while (cin >> t)
	{
		if (t == 0)
		{
			break;
		}
		eatNL;
		for (i = 0; i < t; ++i)
		{
			cin.getline(teams[i].name, sizeof(teams[i].name));
			teams[i].win = teams[i].winMLoss = teams[i].totalPoint = 0;
		}
		cin >> m;
		eatNL;
		while (m--)
		{
			cin.getline(token, sizeof(token));
			name = strtok(token, ":");
			p = strtok(NULL, " \t\n");
			j = win1 = win2 = p1 = p2 = 0;
			while (p)
			{
				sscanf(p, "%d%d", &temp1, &temp2);
				temp2 = temp2 * -1;
				p1 += temp1;
				p2 += temp2;
				if (temp1 >= 25 && (temp1 - temp2) >= 2)
				{
					++win1;
				}
				else
				{
					++win2;
				}
				++j;
				p = strtok(NULL, " \t\n");
			}
			name1 = strtok(name, "-");
			name2 = strtok(NULL, "\n");
			index1 = searchTeams(name1, t);
			index2 = searchTeams(name2, t);
			if (win1 >= 3)
			{
				teams[index1].win++;
				teams[index1].winMLoss += win1 - win2;
				teams[index1].totalPoint += p1;
				teams[index2].winMLoss += win2 - win1;
				teams[index2].totalPoint += p2;
			}
			else
			{
				teams[index2].win++;
				teams[index2].winMLoss += win2 - win1;
				teams[index2].totalPoint += p2;
				teams[index1].winMLoss += win1 - win2;
				teams[index1].totalPoint += p1;
			}
		}
		sort(teams, teams + t, cmp);
		for (i = 0; i < t; ++i)
		{
			printf("%-20s", teams[i].name);
			printf("%5d", teams[i].win);
			printf("%5d", teams[i].winMLoss);
			printf("%10d\n", teams[i].totalPoint);
		}
		printf("\n");
	}
	return 0;
}
