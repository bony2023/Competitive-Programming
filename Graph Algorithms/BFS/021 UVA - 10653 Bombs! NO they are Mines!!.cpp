// Author : Bony Roopchandani
// 10653 - Bombs! NO they are Mines!!
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

bool vis[1001][1001];
int dist[1001][1001];

int R, C;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

int valid(int i, int j)
{
	return ((i >= 0 && i < R) && (j >= 0 && j < C));
}

int main(void)
{
	queue<PII>Q;
	while (1)
	{
		memset(vis, 0, sizeof vis);
		sfi(R);
		sfi(C);

		if (!R && !C)
			break;

		int L, N, x, I;
		sfi(L);
		rep(i, L)
		{
			sfi(I);
			sfi(N);

			rep(j, N)
			{
				sfi(x);
				vis[I][x] = 1;
			}
		}

		PII u, v;
		sfi(u.ff);
		sfi(u.ss);
		sfi(v.ff);
		sfi(v.ss);
		
		vis[u.ff][u.ss] = 1;
		dist[u.ff][u.ss] = 0;
		Q.push(u);

		while (!Q.empty())
		{
			PII z = Q.front();
			if (z == v)
			{
				pfi(dist[z.ff][z.ss]);
				break;
			}
			Q.pop();

			rep(i, 4)
			{
				int x = z.ff + dx[i];
				int y = z.ss + dy[i];

				if (!vis[x][y] && valid(x, y))
				{
					vis[x][y] = 1;
					dist[x][y] = dist[z.ff][z.ss] + 1;
					Q.push(mp(x, y));
				}
			}
		}
		
		while(!Q.empty())
		Q.pop();
	}

	return 0;
}