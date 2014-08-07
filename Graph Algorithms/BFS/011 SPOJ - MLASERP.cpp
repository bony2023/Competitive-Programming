// Author : Bony Roopchandani
// MLASERP
// BFS

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<list>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
#define pb push_back
#define sz size()
#define mp make_pair
#define ff first
#define ss second
#define bg begin()
#define en end()
#define rep(i, n) for(int i=0; i<n; i++)
#define repi(i, n) for(int i=0; i<=n; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define ll long long
#define repl(i, n) for(ll i=0; i<n; i++)
#define repli(i, n) for(ll i=0; i<=n; i++)
#define pfi(a) printf("%d\n",a)
#define sfi(a) scanf("%d",&a)
#define pfl(a) printf("%lld\n",(ll)a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define pfs(a) printf("%s\n",a)
#define pf(a) printf("%d ",a)
#define nl printf("\n")
#define INF 9999999
#define MOD 1000000007
typedef vector < int >VI;
typedef vector < ll > VL;
typedef pair < int, int >PII;
typedef pair < int, ll > PIL;
typedef pair < ll, int >PLI;
typedef pair < int, PII > PIII;
typedef map < int, int >MII;
typedef map < ll, int >MLI;
typedef map < int, ll > MIL;
typedef list < int >LI;
typedef list < ll > LL;

char foo[101][101];
int R, C;
int dist[101][101];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

int valid(int i, int j)
{
	if (i >= 0 && j >= 0 && i < R && j < C)
		return 1;

	return 0;
}

int BFS(PII S, PII E)
{
	memset(dist, INF, sizeof dist);
	dist[S.ff][S.ss] = -1;

	queue < PII > Q;
	Q.push(S);

	while (!Q.empty())
	{
		PII z = Q.front();
		if (z == E)
			return dist[E.ff][E.ss];
		Q.pop();

		rep(i, 4)
		{
			int x = z.ff + dx[i];
			int y = z.ss + dy[i];

			while (valid(x, y) && (foo[x][y] == '.' || foo[x][y] == 'C'))
			{
				if(dist[x][y]>dist[z.ff][z.ss]+1)
				{
				dist[x][y] = dist[z.ff][z.ss] + 1;
				Q.push(mp(x, y));
				}

				x += dx[i];
				y += dy[i];
			}
		}
	}
}


int main(void)
{
	sfi(C);
	sfi(R);
	PII E, S;
	int togg = 0;

	rep(i, R)
	{
		sfs(foo[i]);
		rep(j, C)
		{
			if (foo[i][j] == 'C' && togg == 0)
			{
				S = mp(i, j);
				togg = 1;
			}
			else if (foo[i][j] == 'C' && togg == 1)
			{
				E = mp(i, j);
				togg = INF;
			}
		}
	}

	pfi(BFS(S, E));

	return 0;
}