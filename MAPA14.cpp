#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define F first
#define S second
#define MAXN 100035

vector<int>graph[MAXN];
bool vis[MAXN];
int cnt;

void dfs(int x)
{
	cnt++;
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
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	scanf("%d", &n);
	for(int i=0; i<n-1; i++)
	{
		int x, y, c;
		scanf("%d %d %d", &x, &y, &c);
		x--; y--;
		if(c==0)
		{
			graph[x].pb(y);
			graph[y].pb(x);
		}
	}

	memset(vis, false, n);
	ll total=(ll) n * (n-1)/2;
	for(int i=0; i<n; i++)
	{
		if(!vis[i])
		{
			cnt=0;
			dfs(i);
			total-=(ll)cnt * (cnt-1)/2;
		}
	}
	printf("%lld\n", total);
	return 0;
}