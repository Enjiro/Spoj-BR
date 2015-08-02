#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define F first
#define S second
#define MAXN 50035

vector<int>graph[MAXN];
bool vis[MAXN];

void dfs(int x)
{
	vis[x]=true;
	for(int i=0; i<graph[x].size(); i++)
	{
		int v=graph[x][i];
		if(!vis[v])
			dfs(v);
	}
}

int main()
{
	int n, m;
	int x, y;
	scanf("%d %d", &n, &m);
	while(m--)
	{
		scanf("%d %d", &x, &y);
		x--; y--;
		graph[x].pb(y);
		graph[y].pb(x);
	}

	int cnt=0;
	memset(vis, false, sizeof vis);
	for(int i=0; i<n; i++)
	{
		if(!vis[i])
		{
			cnt++;
			dfs(i);
		}
	}
	printf("%d\n", cnt);
}
