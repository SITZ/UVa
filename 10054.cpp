#include <bits/stdc++.h>

using namespace std;

const int MAXN = 51;

bool visited[MAXN];
int n, adj[MAXN][MAXN], degree[MAXN];
deque<int> path;

void visit_component(int u)
{
	if (visited[u])
	{
		return;
	}
	visited[u] = true;
	for (int v = 0; v < n; ++v)
	{
		if (adj[u][v])
		{
			visit_component(v);
		}
	}
}

void euler(int u)
{
	for (int v = 0; v < n; ++v)
	{
		if (adj[u][v])
		{
			adj[u][v]--;
			adj[v][u]--;
			euler(v);
		}
	}
	path.push_front(u);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		if (t > 1)
		{
			printf("\n");
		}
		printf("Case #%d\n", t);

		bzero(visited, sizeof visited);
		bzero(adj, sizeof adj);
		bzero(degree, sizeof degree);
		path.clear();
		n = 0;

		int edges;
		for (scanf("%d", &edges); edges--;)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			n = max(n, u + 1);
			n = max(n, v + 1);
			degree[u]++;
			degree[v]++;
			adj[u][v]++;
			adj[v][u]++;
		}

		for (int i = 0; i < n; ++i)
		{
			if (degree[i] > 0)
			{
				visit_component(i);
				break;
			}
		}

		bool impossible = false;
		for (int i = 0; i < n; ++i)
		{
			if (degree[i] > 0 && !visited[i] || degree[i] % 2 == 1)
			{
				impossible = true;
				break;
			}
		}

		if (!impossible)
		{
			for (int i = 0; i < n; ++i)
			{
				if (degree[i] > 0)
				{
					euler(i);
					break;
				}
			}
		}

		if (impossible)
		{
			printf("some beads may be lost\n");
		}
		else
		{
			for (int i = 0; i < path.size() - 1; ++i)
			{
				printf("%d %d\n", path[i], path[i + 1]);
			}
		}
	}
	return 0;
}
