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

int mod(int x, int y)
{
	int r=x%y;
	if(r<0)
		r+=y;
	return r;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t[4];
	int x, y;
	for(int i=0; i<4; i++)
	{
		scanf("%d:%d", &x, &y);
		t[i]=(60*x)+y;
	}
	int d[2];
	d[0] = t[1] - t[0];
	d[1] = t[3] - t[2];

	int f = mod( (d[0]+d[1])/2, 720);
	int m = mod( d[0]-f, 1440)/60;

	if(m>12)
		m-=24;

	printf("%d %d\n", f, m);
}